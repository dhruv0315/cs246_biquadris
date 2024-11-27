#include "board.h"
#include <algorithm>

Board::Board() : grid{height, vector<char>(width, ' ')} {}

bool Board::isLineFull(int row) const {
    if (row < 0 || row >= height) {
        return false; // Invalid row index
    }
    return all_of(grid[row].begin(), grid[row].end(), [](char c) { return c != ' '; });
}

void Board::clearFullRow(int row) {
    if (row < 0 || row >= height) { // Invalid row index
        cout << "CLEARING INVALID ROW INDEX" << endl; 
        return; 
    }
    // Shift all rows above the cleared row down
    for (int i = row; i > 0; --i) {
        grid[i] = grid[i - 1];
    }
    // Clear the topmost row
    grid[0] = vector<char>(width, ' ');
}


char Board::getCell(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
      return grid[y][x];
    } else {
			cout << "getting cell out of bound" << endl; //print error message when out of bound
			return '\0';
		}
}

void Board::setCell(int x, int y, char value) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x] = value;
    } else {
			cout << "setting cell out of bound" << endl; //print error message when out of bound
		}
}



void Board::printBoard() const {
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            // If blind effect is active, obscure part of the board with '?'
            if (isBlind && row >= 3 && row <= 12 && col >= 3 && col <= 9) {
                cout << '?'; // blinded
            } else {
                cout << grid[row][col]; // Print the actual cell content
            }
        }
        cout << '\n';
    }
    
}

void Board::reset() {
    grid = vector<vector<char>>(height, vector<char>(width, ' '));
}

