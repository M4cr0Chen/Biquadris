#include "cell.h"

Cell::Cell(int x, int y, char type) : xCoordinate{x}, yCoordinate{y}, type{type} {}

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

void Cell::setCellType(char type)
{
    this->type = type;
}

bool Cell::isFilled()
{
    return type == ' ';
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
