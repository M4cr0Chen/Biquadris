#include "oblock.h"

OBlock::OBlock(int level)
{
    setBottomLeftCell(nullptr);
    setLevel(level);
    setBlockType('O');
    setRotationIndex(0);
    setWidth(2);
}

void OBlock::init(Cell *bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> &grid)
{
    // setBoard(board);
    gridRef = &grid;
    // std::vector<Cell *> cells = getCells();
    // Board *board = getBoard();
    setBottomLeftCell(bottomLeftCell);
    cells.emplace_back((*gridRef)[2][0].get());
    cells.emplace_back((*gridRef)[2][1].get());
    cells.emplace_back((*gridRef)[3][0].get());
    cells.emplace_back((*gridRef)[3][1].get());
    (*gridRef)[2][0]->setCellType(getBlockType());
    (*gridRef)[2][1]->setCellType(getBlockType());
    (*gridRef)[3][0]->setCellType(getBlockType());
    (*gridRef)[3][1]->setCellType(getBlockType());
}

bool OBlock::rotateClockwise()
{
    return true;
}

bool OBlock::rotateCounterClockwise()
{
    return true;
}
