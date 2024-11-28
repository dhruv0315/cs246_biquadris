#include "game.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

Game::Game(int startingLevel)
    : turnNumber(0), gameOver(false), Block1(nullptr), Block2(nullptr), player1{new Player(Level::initLevel(startingLevel),new Board())}, 
		player2{new Player(Level::initLevel(startingLevel),new Board())} {
    // Initialize two players
    currentPlayer = 1;          // Player 1 starts the game

		Block1 = nullptr;
		Block2 = nullptr;

}

Game::~Game() {
    // Free allocated memory
    delete player1;
    delete player2;
		delete Block1;
		delete Block2;
}

void Game::start() {
    while (!gameOver) {
        string command;
        cout << "Player " << currentPlayer  << "'s turn: ";
        getline(cin, command);

        if (cin.eof()) {
            gameOver = true;
            break;
        }

				if (player1->getLevel()->getLevel() == 0){
						Block1 = player1->getLevel()->generateBlock(1);
				} else {
						Block1 = player1->getLevel()->generateBlock();
				}
				
				Block2 = player2->getLevel()->generateBlock();

        try {
            executeCommand(command);
        } catch (const exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    cout << "Game over!" << endl;
}

void Game::executeCommand(const string &command) {
    int multiplier = 1; // Default multiplier is 1
    string actualCommand;

    istringstream iss(command);
    if (!(iss >> multiplier)) {
        // If the first part of the command is not an integer, reset multiplier to 1
        multiplier = 1;
        iss.clear(); // Clear the error state
        iss = istringstream(command); // Reset the stream to the entire command
    } else {
        // Successfully parsed a multiplier, continue parsing the rest of the command
        iss >> actualCommand;
    }


    // Call processCommand with the parsed multiplier and actual command
    processCommand(actualCommand, multiplier);
}


void Game::processCommand(const std::string &command, int multiplier) {
    if (command == "restart") {
      restartGame();
      return;
    }

		Block * currentBlock = Block1;
		if (currentPlayer == 1) {

		} else {
			currentBlock = Block2;
		}

    for (int i = 0; i < multiplier; ++i) {
        if (command == "left") {
            currentBlock->moveLeft();
        } else if (command == "right") {
            currentBlock->moveRight();
        } else if (command == "down") {
            currentBlock->moveDown();
        } else if (command == "clockwise") {
            currentBlock->rotateClockwise();
        } else if (command == "counterclockwise") {
            currentBlock->rotateClockwise();
        } else if (command == "drop") {
            currentBlock->dropToBottom();
						currentBlock->placeOnBoard();
						delete currentBlock;
						if (currentPlayer == 1) {
							Block1 = 
						} else {
							Block2 = 
						}						
            switchToNextPlayer(); // A drop ends the turn
            break;
        } else if (command == "levelup") {
            level->increaseLevel();
        } else if (command == "leveldown") {
            level->decreaseLevel();
        } else if (command == "random") {
            level->setRandom(true);
        } else if (command == "norandom") {
            level->setRandom(false);
        } else if (command == ("IJLOSTZ")) {
            currentPlayer->replaceCurrentBlock(command[0]);
        } else {
            std::cerr << "Invalid command: " << command << std::endl;
        }
    }
}

void Game::switchToNextPlayer() {
    // Toggle between Player 1 and Player 2
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    ++turnNumber;

    if (turnNumber % 2 == 0) {
        std::cout << "Both players have completed a turn." << std::endl;
    }
}

void Game::restartGame() {
    turnNumber = 0;
    currentPlayer = 1;
    gameOver = false;

    // Reset both players
    player1->getBoard()->reset();
    player2->getBoard()->reset();

    // Reset the level
    Level* level = Level::initLevel(0);

    std::cout << "Game restarted." << std::endl;
}

