#include "board.h"
#include <iostream>

Board::Board() : nextBlockType{' '}, currentBlock{nullptr}, nextBlock{nullptr}, level{0}, isHeavy{false}, isBlind{false}
{
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

Cell *Board::getCellAt(int x, int y)
{
    return grid[x][y].get();
}

char Board::getNextBlockType()
{
    return nextBlockType;
}

void Board::addBlock(std::unique_ptr<Block> newblock)
{
    // testing purpose
    // activeBlocks.emplace_back(std::move(newblock));

    if (nextBlock == nullptr)
    {
        nextBlock = std::move(newblock);
        return;
    }

    // currentBlock = activeBlocks[activeBlocks.size() - 1].get();
    currentBlock = std::move(nextBlock);
    nextBlock = std::move(newblock);
    currentBlock->init(grid[3][0].get(), grid);
}

void Board::changeBlock(std::unique_ptr<Block> block)
{
    currentBlock = std::move(block);
    // if (currentBlock->getBlockType() == '*')
    // {
    //     currentBlock->init(grid[3][5].get(), grid);
    //     return;
    // }
    currentBlock->init(grid[3][0].get(), grid);
}

void Board::insertBlock(std::unique_ptr<Block> block)
{
    tempBlock = std::move(block);
    tempBlock->init(grid[3][5].get(), grid);
}

bool Board::isRowFull(int row)
{
    for (int i = 0; i < 11; i++)
    {
        if (grid[row][i]->getCellType() == ' ')
        {
            return false;
        }
    }

    return true;
}

void Board::moveRowDown(int row, int destRow)
{
    for (int i = 0; i < 11; i++)
    {
        grid[destRow][i]->setCellType(grid[row][i]->getCellType());
    }
}

int Board::updateActiveBlocks()
{
    int score = 0;
    for (int i = activeBlocks.size() - 1; i >= 0; i--)
    {
        int blockScore = 0;
        blockScore = activeBlocks[i]->updateBlock();

        if (blockScore > 0)
        {
            activeBlocks.erase(activeBlocks.begin() + i);
        }

        score += blockScore;
    }

    return score;
}

void moveCellsDownByOne(std::vector<Cell *> cellsToBeMoved)
{
    for (Cell *cell : cellsToBeMoved)
    {
        cell->setCoordinate(cell->getX() + 1, cell->getY());
    }
}

void Board::updateBlocksPosition(int clearedRow)
{
    for (int i = 0; i < activeBlocks.size(); i++)
    {
        // activeBlocks[i]->setBottomLeftCell(grid[activeBlocks[i]->getBottomLeftCell()->getX()][activeBlocks[i]->getBottomLeftCell()->getY()].get());
        std::vector<Cell *> cellsToBeMoved;
        for (Cell *cell : activeBlocks[i]->getCells())
        {
            if (cell->getX() < clearedRow)
            {
                cellsToBeMoved.push_back(cell);
            }
        }
        moveCellsDownByOne(cellsToBeMoved);
    }
}

void Board::setRowEmpty(int row)
{
    for (int i = 0; i < 11; i++)
    {
        grid[row][i]->setCellType(' ');
    }
}

void Board::dropBlock(int *numLine, int *dropScore)
{
    if (currentBlock == nullptr)
    {
        return;
    }

    int score = 0;
    int linesFull = 0;

    currentBlock->drop();
    activeBlocks.push_back(std::move(currentBlock));

    // if (tempBlock != nullptr)
    // {
    //     currentBlock = std::move(tempBlock);
    //     currentBlock->drop();
    //     currentBlock = nullptr;
    //     tempBlock = nullptr;
    // }

    // std::cout << "activeBlocks size: " << activeBlocks.size() << std::endl;

    // clearline logic
    int blockRow = 17;
    while (blockRow >= 0)
    {
        if (isRowFull(blockRow))
        {
            linesFull++;
            setRowEmpty(blockRow);
            score += updateActiveBlocks();
            // moveRowDown(blockRow - 1, blockRow);
            updateBlocksPosition(blockRow);
            for (int i = blockRow; i >= 2; i--)
            {
                moveRowDown(i - 1, i);
            }
        }
        else
        {
            blockRow--;
        }
    }

    // currentBlock = nullptr;

    if (level == 4)
    {
        if (linesFull > 0)
        {
            // reset count
            count = 0;
        }
        else
        {
            // increment count
            count++;
        }
    }

    if (linesFull > 0)
    {
        *numLine = linesFull;
        // score += std::pow(linesFull + level, 2);
        *dropScore = score;
    }
}

void Board::dropStarBlock(int *numLine, int *dropScore) 
{
    if (tempBlock == nullptr)
    {
        return;
    }

    int score = 0;
    int linesFull = 0;

    tempBlock->drop();
    activeBlocks.push_back(std::move(tempBlock));

    // if (tempBlock != nullptr)
    // {
    //     currentBlock = std::move(tempBlock);
    //     currentBlock->drop();
    //     currentBlock = nullptr;
    //     tempBlock = nullptr;
    // }

    // std::cout << "activeBlocks size: " << activeBlocks.size() << std::endl;

    // clearline logic
    int blockRow = 17;
    while (blockRow >= 0)
    {
        if (isRowFull(blockRow))
        {
            linesFull++;
            setRowEmpty(blockRow);
            score += updateActiveBlocks();
            // moveRowDown(blockRow - 1, blockRow);
            updateBlocksPosition(blockRow);
            for (int i = blockRow; i >= 2; i--)
            {
                moveRowDown(i - 1, i);
            }
        }
        else
        {
            blockRow--;
        }
    }

    // currentBlock = nullptr;

    // if (level == 4)
    // {
    //     if (linesFull > 0)
    //     {
    //         // reset count
    //         count = 0;
    //     }
    //     else
    //     {
    //         // increment count
    //         count++;
    //     }
    // }

    if (linesFull > 0)
    {
        *numLine += linesFull;
        // score += std::pow(linesFull + level, 2);
        *dropScore = score;
    }
}

void Board::setLevel(int level)
{
    this->level = level;
    setCount(0);
}

void Board::setCount(int count)
{
    this->count = count;
}

Block *Board::getCurrentBlock()
{
    return currentBlock.get();
}

Block *Board::getNextBlock()
{
    return nextBlock.get();
}

int Board::getHeavyInt()
{
    if (isHeavy)
    {
        return 2;
    }

    return 0;
}

int Board::getCount()
{
    return count;
}

void Board::setBoardBlind()
{
    isBlind = !isBlind;
}

void Board::setBoardHeavy()
{
    isHeavy = !isHeavy;
}

bool Board::isGameOver()
{
    // if (currentBlock == nullptr)
    // {
    //     return false;
    // }

    for (int i = 0; i < 11; i++)
    {
        if (grid[3][i]->getCellType() != ' ')
        {
            return true;
        }
    }

    return false;
}
