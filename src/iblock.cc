#include "iblock.h"

IBlock::IBlock(int level)
{
    setLevel(level);
    setBlockType('I');
    std::vector<Cell *> cells = getCells();
    Board *board = getBoard();
    Cell *bottomLeftCell = getBottomLeftCell();
    cells.emplace_back(board->getCellAt(3, 0));
    cells.emplace_back(board->getCellAt(3, 1));
    cells.emplace_back(board->getCellAt(3, 2));
    cells.emplace_back(board->getCellAt(3, 3));
    bottomLeftCell = cells[0];
}
