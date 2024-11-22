#include "iblock.h"

IBlock::IBlock(int level)
{
    setLevel(level);
    setBlockType('I');
}

void IBlock::init(Cell * bottomLeftCell, std::vector<std::vector<std::unique_ptr<Cell>>> & grid)
{
    //setBoard(board);
    std::vector<Cell *> cells = getCells();
    //Board *board = getBoard();
    setBottomLeftCell(bottomLeftCell);
    cells.emplace_back(grid[3][0].get());
    cells.emplace_back(grid[3][1].get());
    cells.emplace_back(grid[3][2].get());
    cells.emplace_back(grid[3][3].get());
    grid[3][0]->setCellType('I');
    grid[3][1]->setCellType('I');
    grid[3][2]->setCellType('I');
    grid[3][3]->setCellType('I');
}

bool IBlock::moveLeft() {}

bool IBlock::moveRight() {}

bool IBlock::moveDown() {}

void IBlock::drop() {}

bool IBlock::rotateClockwise() {}

bool IBlock::rotateCounterClockwise() {}
