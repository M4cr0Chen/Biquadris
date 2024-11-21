#include "board.h"

Board::Board() : nextBlockType{' '} {
    grid.resize(18);
    for (int i = 0; i < 18; i++)
    {
        grid[i].resize(11);
        for (int j = 0; j < 11; j++)
        {
            grid[i][j] = std::make_unique<Cell>(i, j, ' ');
        }
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
