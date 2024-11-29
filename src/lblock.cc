#include "lblock.h"

LBlock::LBlock(int level)
{
    setBottomLeftCell(nullptr);
    setLevel(level);
    setBlockType('L');
    setRotationIndex(0);
    setWidth(3);
}

void LBlock::init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid)
{
    gridRef = &grid;
    if (playerLose())
        throw std::runtime_error("Game is over");
    setBottomLeftCell(bottomLeftCell);
    cells.emplace_back(bottomLeftCell);
    cells.emplace_back((*gridRef)[3][1].get());
    cells.emplace_back((*gridRef)[3][2].get());
    cells.emplace_back((*gridRef)[2][2].get());
    (*gridRef)[3][1]->setCellType(getBlockType());
    (*gridRef)[3][2]->setCellType(getBlockType());
    (*gridRef)[2][2]->setCellType(getBlockType());
    bottomLeftCell->setCellType(getBlockType());
}

bool LBlock::rotateClockwise()
{
    std::vector<Cell *> tempCells;
    rotationIndex = getRotationIndex();

    if (rotationIndex == 0)
    {
        Cell *bottomLeftCell = getBottomLeftCell();
        Board *board = getBoard();
        int x = bottomLeftCell->getX();
        int y = bottomLeftCell->getY();


        tempCells.push_back((*gridRef)[x][y].get());     // Bottom
        tempCells.push_back((*gridRef)[x][y + 1].get()); // Second from bottom
        tempCells.push_back((*gridRef)[x - 1][y].get()); // Second from top
        tempCells.push_back((*gridRef)[x - 2][y].get()); // Top

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

        tempCells.push_back((*gridRef)[x][y].get());         // Left
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


        tempCells.push_back((*gridRef)[x][y + 1].get());     // Left
        tempCells.push_back((*gridRef)[x - 1][y + 1].get()); // Second from left
        tempCells.push_back((*gridRef)[x - 2][y].get());     // Second from right
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

        tempCells.push_back((*gridRef)[x][y].get());         // Left
        tempCells.push_back((*gridRef)[x][y + 1].get());     // Second from left
        tempCells.push_back((*gridRef)[x][y + 2].get());     // Second from right
        tempCells.push_back((*gridRef)[x - 1][y + 2].get()); // Right

        if (isValidMove(tempCells))
        {
            width = 3;
            rotationIndex = (rotationIndex + 1) % 4;
        }

       
    }

    if (isValidMove(tempCells))
    {
        for (Cell *cell : tempCells)
        {
            cell->setCellType(getBlockType());
        }
        cells = tempCells;
        return true;
    }
    return false;
}

bool LBlock::rotateCounterClockwise()
{
   
    bool success = true;
    for (int i = 0; i < 3 && success; i++)
    {
        success = rotateClockwise();
    }
    return success;
}

LBlock::~LBlock()
{
    bottomLeftCell = nullptr;
    for (Cell *cell : cells)
    {
        cell->setCellType(' ');
    }
}
