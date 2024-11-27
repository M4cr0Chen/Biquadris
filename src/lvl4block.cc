#include "lvl4block.h"

LVL4Block::LVL4Block(int level)
{
    setBottomLeftCell(nullptr);
    setLevel(level);
    setBlockType('*');
    setRotationIndex(0);
    setWidth(1);
}

void LVL4Block::init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid)
{
    // setBoard(board);
    gridRef = &grid;
    // std::vector<Cell *> cells = getCells();
    // Board *board = getBoard();
    if (playerLose())
        throw std::runtime_error("Game is over");
    setBottomLeftCell(bottomLeftCell);
    (*gridRef)[3][5]->setCellType(getBlockType());
}

bool LVL4Block::rotateClockwise()
{
    return true;
}

bool LVL4Block::rotateCounterClockwise()
{
    return true;
}

LVL4Block::~LVL4Block()
{
    bottomLeftCell = nullptr;
    for (Cell *cell : cells)
    {
        cell->setCellType(' ');
    }
}
