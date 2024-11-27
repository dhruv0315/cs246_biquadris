#ifndef PLAYER_H
#define PLAYER_H

#include "block.h"
#include "board.h"
#include "Level.h"


class Player {
private:
    Board *board;
    Level *level;
    int score;
    int turnsSinceDebuff;
public:
    Player(Level* startingLevel, Board *playerBoard);
    ~Player();

    Board *getBoard() const;
    int getScore();
    int getLevel();
    int getTurnsSinceDebuff();

    void updateScore(int points);
    void applyDebuff(Debuff *debuff);
    void incLevel();
    void decLevel();
    void incTurnsSinceDebuff();
    void resetTurnsSinceDebuff();
};

#endif
