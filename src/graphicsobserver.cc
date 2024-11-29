// graphicsobserver.cc
#include "graphicsobserver.h"
#include "game.h"
#include "player.h"
#include <string>

// Constants for graphical representation
int WINDOW_WIDTH = 600;
int WINDOW_HEIGHT = 800;
int BOARD_WIDTH = 11;
int BOARD_HEIGHT = 18;
int CELL_SIZE = 25;
int INFO_HEIGHT = 100;
int NEXT_BLOCK_HEIGHT = 60;
int MARGIN = 10;

GraphicsObserver::GraphicsObserver(Game &game)
    : game(game), xw{std::make_unique<Xwindow>(WINDOW_WIDTH, WINDOW_HEIGHT)}
{
    // Attach this observer to the game
    // game.attach(this);
}

GraphicsObserver::~GraphicsObserver() = default;

void GraphicsObserver::drawLevel(Player * player, int xOffset, int yOffset)
{
    int level = player->getIntLevel();
    xw->drawString(xOffset, yOffset, "Level: " + std::to_string(level));
}

void GraphicsObserver::drawScore(Player *player, int xOffset, int yOffset)
{
    int score = player->getScore().getCurrentScore();
    xw->drawString(xOffset, yOffset, "Score: " + std::to_string(score));
}

void GraphicsObserver::drawHighScore(Player *player, int xOffset, int yOffset)
{
    int highScore = player->getScore().getHighScore();
    xw->drawString(xOffset, yOffset, "Hi Score: " + std::to_string(highScore));
}

void GraphicsObserver::drawPlayerBoard(Player *player, int xOffset, int yOffset)
{
    Board &board = player->getBoard();
    bool isBlind = board.getIsBlind();

    for (int row = 0; row < BOARD_HEIGHT; ++row)
    {
        for (int col = 0; col < BOARD_WIDTH; ++col)
        {
            Cell *cell;
            char cellType;
            if (isBlind && row >= 2 && row <= 11 && col >= 2 && col <= 8)
            {
                cellType = '?';
            }
            else
            {
                cell = board.getCellAt(row, col);
                cellType = cell->getCellType();
            }
            int color = getColor(cellType);

            int x = xOffset + col * CELL_SIZE;
            int y = yOffset + row * CELL_SIZE;

            // Draw the segmentation border in white
            xw->fillRectangle(x, y, CELL_SIZE, CELL_SIZE, Xwindow::White);

            // Draw the cell slightly smaller to reveal the border
            xw->fillRectangle(x + 1, y + 1, CELL_SIZE - 2, CELL_SIZE - 2, color);
        }
    }
}

void GraphicsObserver::drawNextBlock(Player *player, int xOffset, int yOffset)
{
    xw->drawString(xOffset, yOffset, "Next:");

    char nextBlockType = player->getBoard().getNextBlockType();
    std::vector<std::vector<char>> blockPattern;

    switch (nextBlockType)
    {
    case 'I':
        blockPattern = {{'I', 'I', 'I', 'I'}};
        break;
    case 'J':
        blockPattern = {{'J', ' ', ' '}, {'J', 'J', 'J'}};
        break;
    case 'L':
        blockPattern = {{' ', ' ', 'L'}, {'L', 'L', 'L'}};
        break;
    case 'O':
        blockPattern = {{'O', 'O'}, {'O', 'O'}};
        break;
    case 'S':
        blockPattern = {{' ', 'S', 'S'}, {'S', 'S', ' '}};
        break;
    case 'Z':
        blockPattern = {{'Z', 'Z', ' '}, {' ', 'Z', 'Z'}};
        break;
    case 'T':
        blockPattern = {{'T', 'T', 'T'}, {' ', 'T', ' '}};
        break;
    default:
        blockPattern = {{' '}};
        break;
    }

    int blockXOffset = xOffset;
    int blockYOffset = yOffset + 20;

    for (size_t row = 0; row < blockPattern.size(); ++row)
    {
        for (size_t col = 0; col < blockPattern[row].size(); ++col)
        {
            char cellType = blockPattern[row][col];
            int color = getColor(cellType);

            int x = blockXOffset + col * CELL_SIZE;
            int y = blockYOffset + row * CELL_SIZE;

            if (cellType != ' ')
            {
                // Draw the segmentation border in white
            xw->fillRectangle(x, y, CELL_SIZE, CELL_SIZE, Xwindow::White);

            // Draw the cell slightly smaller to reveal the border
            xw->fillRectangle(x + 1, y + 1, CELL_SIZE - 2, CELL_SIZE - 2, color);
            }
        }
    }
}

int GraphicsObserver::getColor(char cellType)
{
    switch (cellType)
    {
    case 'I':
        return Xwindow::Blue;
    case 'J':
        return Xwindow::Purple;
    case 'L':
        return Xwindow::Orange;
    case 'O':
        return Xwindow::Yellow;
    case 'S':
        return Xwindow::Green;
    case 'Z':
        return Xwindow::Red;
    case 'T':
        return Xwindow::Magenta;
    case '*': // For special blocks or stars
        return Xwindow::Brown;
    case '?': // For blinded cells
        return Xwindow::Black;
    case ' ': // Empty cell
        return Xwindow::White;
    default:
        return Xwindow::Black;
    }
}

void GraphicsObserver::drawBoard()
{
    // Clear the window
    xw->fillRectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, Xwindow::White);

    // Draw Player One's components
    int playerOneXOffset = MARGIN;
    int playerOneYOffset = MARGIN;

    drawLevel(game.getPlayerOne(), playerOneXOffset, playerOneYOffset);
    drawScore(game.getPlayerOne(), playerOneXOffset, playerOneYOffset + 20);
    drawHighScore(game.getPlayerOne(), playerOneXOffset, playerOneYOffset + 40);
    drawPlayerBoard(game.getPlayerOne(), playerOneXOffset, playerOneYOffset + INFO_HEIGHT);
    drawNextBlock(game.getPlayerOne(), playerOneXOffset, playerOneYOffset + INFO_HEIGHT + BOARD_HEIGHT * CELL_SIZE + MARGIN);

    // Draw Player Two's components
    int playerTwoXOffset = WINDOW_WIDTH / 2 + MARGIN;
    int playerTwoYOffset = MARGIN;

    drawLevel(game.getPlayerTwo(), playerTwoXOffset, playerTwoYOffset);
    drawScore(game.getPlayerTwo(), playerTwoXOffset, playerTwoYOffset + 20);
    drawHighScore(game.getPlayerTwo(), playerTwoXOffset, playerTwoYOffset + 40);
    drawPlayerBoard(game.getPlayerTwo(), playerTwoXOffset, playerTwoYOffset + INFO_HEIGHT);
    drawNextBlock(game.getPlayerTwo(), playerTwoXOffset, playerTwoYOffset + INFO_HEIGHT + BOARD_HEIGHT * CELL_SIZE + MARGIN);
}
