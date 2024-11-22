#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

#include "cell.h"

class Block
{
private:
    std::vector<Cell *> cells;
    char blockType;
    int level;
    int anchorX, anchorY;
    bool heavy;

public:
    // Destructor
    virtual ~Block() = default;

    // Movement methods
    virtual bool moveLeft();
    virtual bool moveRight();
    virtual bool moveDown();
    virtual void drop();

    // Rotation methods
    virtual bool rotateClockwise();
    virtual bool rotateCounterClockwise();

    // Position and state queries
    std::vector<Cell *> getCells() const;
    std::vector<Cell *> getProjectedCells(char dir) const;
    char getBlockType() const;
    bool isAtBottom() const;

    // Cell manipulation
    void clearCells();
    bool occupyCells(const std::vector<Cell *> &newCells);

    // For rotation calculations
    std::pair<int, int> getAnchorPosition() const;
    void setAnchorPosition(int x, int y);

    // For level effects
    bool isHeavy() const;
    void setHeavy(bool heavy);
};

#endif
