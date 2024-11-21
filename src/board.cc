#include "board.h"

Board::Board() : nextBlockType{' '} {
    for (int i = 0; i < 18; i++)
    {
        std::vector<std::unique_ptr<Cell>> row;
        for (int j = 0; j < 11; j++)
        {
            row.push_back(std::make_unique<Cell>(i, j));
        }
        grid.push_back(row);
    }
}

Cell &Board::getCell(int x, int y)
{
    return *grid[x][y];
}

char Board::getNextBlockType()
{
    return nextBlockType;
}
