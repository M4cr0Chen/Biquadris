#ifndef CELL_H
#define CELL_H

class Cell
{
private:
    int xCoordinate, yCoordinate;
    char type;
    bool filled;

public:
    int getX();
    int getY();
    int setCoordinate(int x, int y);
    int getType();
    bool isFilled();
};

#endif
