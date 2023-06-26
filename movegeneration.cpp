#include "chessboard.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

/* pawn can move two squares or one square up from starting position otherwise one square up */
int move_pawn(pair<int, int> pos, bool turn) {
    // if pawn has not moved it can move two squares
    set<pair<int, int>> moves;
    pair<int, int> temp;
    if (turn) {
        temp.first +=1;
    } else {
        temp.first -= 1;
    }
    // one square
    pos.second += 1;
    // two squares
    pos.second += 2;
    return pos.second;
}

// take current position of piece and generate all legal moves

int move_knight(pair<int, int> pos) {
    set<pair<int, int>> moves;
    pair<int, int> temp; 

    for (int i = 0; i < )
    while (moves.find(temp) == moves.end()) {
        temp.first = pos.first + 2;
        temp.second = pos.second + 1;
    }
    return 0;
}

int bishop(pair<int, int> pos) {
    for (int i = 0; i < 8; i)
}

int chessboard::move_rook(pair<int, int> pos) {
    set<pair<int, int>> valid_moves;
    for (int i = pos.first; i < ROWS; i++) {
        if (board[i][pos.second] == 0)
            break;
    }
    for (int j = pos.second; j < COLS; j++)

    for (int i = pos.first; i >= 0; i--)

    for (int j = pos.second; j >= 0; j--)

}

int move_queen(pair<int, int> pos) {

}