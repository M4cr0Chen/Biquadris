#include "iblock.h"

IBlock::IBlock(int level)
{
    setLevel(level);
    setBlockType('I');
    setRotationIndex(0);
    setWidth(4);
}

void IBlock::init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid)
{
    // setBoard(board);
    gridRef = &grid;
    // std::vector<Cell *> cells = getCells();
    // Board *board = getBoard();
    if (playerLose())
        throw std::runtime_error("Game is over");
    setBottomLeftCell(bottomLeftCell);
    cells.emplace_back((*gridRef)[3][0].get());
    cells.emplace_back((*gridRef)[3][1].get());
    cells.emplace_back((*gridRef)[3][2].get());
    cells.emplace_back((*gridRef)[3][3].get());
    (*gridRef)[3][0]->setCellType('I');
    (*gridRef)[3][1]->setCellType('I');
    (*gridRef)[3][2]->setCellType('I');
    (*gridRef)[3][3]->setCellType('I');
}

bool IBlock::rotateClockwise()
{
    std::vector<Cell *> tempCells;
    rotationIndex = getRotationIndex();

    // Horizontal to Vertical (0->1, 2->3)
    if (rotationIndex == 0 || rotationIndex == 2)
    {
        Cell *bottomLeftCell = getBottomLeftCell();
        Board *board = getBoard();
        int x = bottomLeftCell->getX();
        int y = bottomLeftCell->getY();

        tempCells.push_back((*gridRef)[x][y].get());     // Bottom
        tempCells.push_back((*gridRef)[x - 1][y].get()); // Second from bottom
        tempCells.push_back((*gridRef)[x - 2][y].get()); // Second from top
        tempCells.push_back((*gridRef)[x - 3][y].get()); // Top

        if (isValidMove(tempCells))
        {
            setWidth(1);
            rotationIndex++;
        }
    }
    // Vertical to Horizontal (1->2, 3->0)
    else
    {
        Cell *bottomLeftCell = getBottomLeftCell();
        Board *board = getBoard();
        int x = bottomLeftCell->getX();
        int y = bottomLeftCell->getY();

        if (y > 7)
            return false;

        tempCells.push_back((*gridRef)[x][y].get());     // Left
        tempCells.push_back((*gridRef)[x][y + 1].get()); // Second from left
        tempCells.push_back((*gridRef)[x][y + 2].get()); // Second from right
        tempCells.push_back((*gridRef)[x][y + 3].get()); // Right

        if (isValidMove(tempCells))
        {
            width = 4;
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

bool IBlock::rotateCounterClockwise()
{
    // Three clockwise rotations = one counterclockwise rotation
    bool success = true;
    for (int i = 0; i < 3 && success; i++)
    {
        success = rotateClockwise();
    }
    return success;
}

IBlock::~IBlock()
{
    bottomLeftCell = nullptr;
    for (Cell *cell : cells)
    {
        cell->setCellType(' ');
    }
}
