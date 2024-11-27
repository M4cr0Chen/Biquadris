#include "score.h"

Score::Score() : currentScore{0}, highScore{0} {}

int Score::getCurrentScore()
{
    return currentScore;
}

int Score::getHighScore()
{
    return highScore;
}

void Score::setCurrentScore(int score)
{
    currentScore = score;
}

void Score::addToCurrentScore(int score)
{
    currentScore += score;
    if (currentScore > highScore)
    {
        highScore = currentScore;
    }
}

void Score::resetCurrentScore()
{
    currentScore = 0;
}
