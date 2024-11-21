#ifndef SCORE_H
#define SCORE_H

class Score
{
private:
    int currentScore;
    int highScore;

public:
    Score();
    ~Score() = default;
    int getCurrentScore();
    int getHighScore();
    void setCurrentScore(int score);
    void addToCurrentScore(int score);
    void resetCurrentScore();
};

#endif
