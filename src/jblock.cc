#include "jblock.h"

JBlock::JBlock(int level)
{
    setBottomLeftCell(nullptr);
    setLevel(level);
    setBlockType('J');
    setRotationIndex(0);
    setWidth(3);
}

void JBlock::init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid)
{
    // setBoard(board);
    gridRef = &grid;
    // std::vector<Cell *> cells = getCells();
    // Board *board = getBoard();
    if (playerLose())
        throw std::runtime_error("Game is over");
    setBottomLeftCell(bottomLeftCell);
    cells.emplace_back(bottomLeftCell);
    cells.emplace_back((*gridRef)[2][0].get());
    cells.emplace_back((*gridRef)[3][1].get());
    cells.emplace_back((*gridRef)[3][2].get());
    (*gridRef)[2][0]->setCellType(getBlockType());
    (*gridRef)[3][1]->setCellType(getBlockType());
    (*gridRef)[3][2]->setCellType(getBlockType());
    bottomLeftCell->setCellType(getBlockType());
}

bool JBlock::rotateClockwise()
{
    std::vector<Cell *> tempCells;
    rotationIndex = getRotationIndex();

    if (rotationIndex == 0)
    {
        Cell *bottomLeftCell = getBottomLeftCell();
        Board *board = getBoard();
        int x = bottomLeftCell->getX();
        int y = bottomLeftCell->getY();

        // if (y > 3)
        //     return false;

        tempCells.push_back((*gridRef)[x][y].get());         // Bottom
        tempCells.push_back((*gridRef)[x - 1][y].get());     // Second from bottom
        tempCells.push_back((*gridRef)[x - 2][y].get());     // Second from top
        tempCells.push_back((*gridRef)[x - 2][y + 1].get()); // Top

        if (isValidMove(tempCells))
        {
            setWidth(2);
            rotationIndex = (rotationIndex + 1) % 4;
        }
    }
    else if (rotationIndex == 1)
    {
        Cell *bottomLeftCell = getBottomLeftCell();
        Board *board = getBoard();
        int x = bottomLeftCell->getX();
        int y = bottomLeftCell->getY();

        if (y > 8)
            return false;

        tempCells.push_back((*gridRef)[x][y + 2].get());     // Left
        tempCells.push_back((*gridRef)[x - 1][y].get());     // Second from left
        tempCells.push_back((*gridRef)[x - 1][y + 1].get()); // Second from right
        tempCells.push_back((*gridRef)[x - 1][y + 2].get()); // Right

        if (isValidMove(tempCells))
        {
            width = 3;
            rotationIndex = (rotationIndex + 1) % 4;
        }
    }
    else if (rotationIndex == 2)
    {
        Cell *bottomLeftCell = getBottomLeftCell();
        Board *board = getBoard();
        int x = bottomLeftCell->getX();
        int y = bottomLeftCell->getY();

        // if (y > 7)
        //     return false;

        tempCells.push_back((*gridRef)[x][y].get());         // Left
        tempCells.push_back((*gridRef)[x][y + 1].get());     // Second from left
        tempCells.push_back((*gridRef)[x - 1][y + 1].get()); // Second from right
        tempCells.push_back((*gridRef)[x - 2][y + 1].get()); // Right

        if (isValidMove(tempCells))
        {
            width = 2;
            rotationIndex = (rotationIndex + 1) % 4;
        }
    }
    else if (rotationIndex == 3)
    {
        Cell *bottomLeftCell = getBottomLeftCell();
        Board *board = getBoard();
        int x = bottomLeftCell->getX();
        int y = bottomLeftCell->getY();

        if (y > 8)
            return false;

        tempCells.push_back((*gridRef)[x][y].get());     // Left
        tempCells.push_back((*gridRef)[x][y + 1].get()); // Second from left
        tempCells.push_back((*gridRef)[x][y + 2].get()); // Second from right
        tempCells.push_back((*gridRef)[x - 1][y].get()); // Right

        if (isValidMove(tempCells))
        {
            width = 3;
            rotationIndex = (rotationIndex + 1) % 4;
        }

        // if (isValidMove(tempCells))
        // {
        //     for (Cell *cell : tempCells)
        //     {
        //         cell->setCellType(getBlockType());
        //     }
        //     bottomLeftCell = tempCells[0];
        //     cells = tempCells;
        // }
        // return false;
    }

    if (isValidMove(tempCells))
    {
        for (Cell *cell : tempCells)
        {
            cell->setCellType(getBlockType());
        }
        // bottomLeftCell = tempCells[0];
        cells = tempCells;
        return true;
    }
    return false;
}

bool JBlock::rotateCounterClockwise()
{
    // Three clockwise rotations = one counterclockwise rotation
    bool success = true;
    for (int i = 0; i < 3 && success; i++)
    {
        success = rotateClockwise();
    }
    return success;
}

JBlock::~JBlock()
{
    bottomLeftCell = nullptr;
    for (Cell *cell : cells)
    {
        cell->setCellType(' ');
    }
}
