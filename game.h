#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
#include "board.h"
#include "Level.h"
#include "block.h"
#include "player.h"

class Game {
private:
    int turnNumber;
    Player * player1;
    Player * player2;
    int currentPlayer;
    bool gameOver;
		Block *Block1;
		Block *Block2;

    void processCommand(const std::string &command, int multiplier = 1);
    void switchToNextPlayer();
    void restartGame();

public:
    Game(int startingLevel = 0);
    ~Game();

    void start();
    void executeCommand(const std::string &command);
};

#endif 

