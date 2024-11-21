#include "cell.h"

Cell::Cell(int x, int y, char type = ' ') : xCoordinate(x), yCoordinate(y), type(type), filled(false) {}

int Cell::getX()
{
    return xCoordinate;
}

int Cell::getY()
{
    return yCoordinate;
}

char Cell::getCellType()
{
    return type;
}

bool Cell::isFilled()
{
    return filled;
}

void Cell::setCoordinate(int x, int y)
{
    xCoordinate = x;
    yCoordinate = y;
}

void Cell::setX(int x)
{
    xCoordinate = x;
}

void Cell::setY(int y)
{
    yCoordinate = y;
}
