#include "player.h"


Player::Player(Level* startingLevel, Board *playerBoard):
    level(startingLevel), board(playerBoard), score(0), turnsSinceDebuff(0) {}

Player::~Player() {
    delete level;
    delete board;
}

Board *Player::getBoard() const {
    return board;
}

int Player::getScore() {
    return score;
}

level* Player::getLevel() {
    return level;
}

int Player::getTurnsSinceDebuff() {
    return turnsSinceDebuff;
}

void Player::updateScore(int points) {
    score += points;
}

bool Player::isHeavied() const{
    return isHeavy;
}

void Player::incLevel() {
    level->incLevel();
}

void Player::decLevel() {
    level->decLevel();
}

void Player::incTurnsSinceDebuff() {
    ++turnsSinceDebuff;
}

void Player::resetTurnsSinceDebuff() {
    turnsSinceDebuff = 0;
}

