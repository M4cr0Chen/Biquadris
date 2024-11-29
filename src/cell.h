#ifndef CELL_H
#define CELL_H

class Cell
{
private:
    int xCoordinate, yCoordinate;
    char type;

public:
    Cell(int x, int y, char type = ' ');
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    void setCoordinate(int x, int y);
    char getCellType();
    void setCellType(char type);
    bool isFilled();
};

#endif
