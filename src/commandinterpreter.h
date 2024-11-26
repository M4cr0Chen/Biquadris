#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H

#include <string>
#include <map>

class Game;

class Interpreter{
    enum CommandType {
        LEFT,
        RIGHT,
        DOWN,
        CLOCKWISE,
        COUNTERCLOCKWISE,
        DROP,
        LEVELUP,
        LEVELDOWN,
        NORANDOM,
        RANDOM,
        SEQUENCE,
        I,
        J,
        L,
        O,
        S,
        Z,
        T,
        RESTART,
        RENAME,
        DEFAULT
    };
    std::map<std::string, CommandType> commandMap;
    Game* game;
    void runLeftCommand(int);
    void runRightCommand(int);
    void runDownCommand(int);
    void runClockwiseCommand(int);
    void runCounterClockwiseCommand(int);
    void runDropCommand(int);
    void runLevelUpCommand(int);
    void runLevelDownCommand(int);
    void runNoRandomCommand(int);
    void runRandomCommand(int);
    void runSequenceCommand(int);
    void runRenameCommand();
    void requestSpecialAction();
    public:
     Interpreter(Game* game);
     void interpret(std::string command);
};

#endif
