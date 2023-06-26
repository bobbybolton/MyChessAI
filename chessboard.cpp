#include <iostream>
#include <string>

#include "chessboard.h"

using namespace std;

/* use FEN notation to draw initial board */


// black lowercase
// white uppercase
void chessboard::draw_board(string fen) {
    int a = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ('0' <= fen[a] && fen[a] <= '9') {
                int k;
                for (k = j; k < j + fen[a] - '0'; k++) {
                    cout << ". ";
                }
                j = k-1;
            } else {
                cout << fen[a] << " ";
            }
            a++;
        }
        cout << endl;
        a++;
    }
}

/* initial board =
r n b q k b n r
p p p p p p p p
. . . . . . . .
. . . . . . . .
. . . . . . . .
. . . . . . . .
P P P P P P P P
R N B Q K B N R

*/

std::vector<std::pair<int, int>> chessboard::move_pawn(std::pair<int, int> pos) {
    vector<pair<int, int>> moves;
    // valid moves
    // one square forward if square is empty
    // two square forward if first move and square is empty
    // capture right/left diagnol if opponent piece is present
    // en passant special case
    moves.push_back({pos.first - 1, pos.second});
    moves.push_back({pos.first - 2, pos.second});

    
    return moves;
}

vector<pair<int, int>> chessboard::move_knight(pair<int, int> pos) {
    vector<pair<int, int>> moves;
    int dirs[8][2] = {{2, 1},{2, -1},{-2, 1},{-2, -1},{1, 2},{1, -2},{-1, 2},{-1, -2}};
    for (int i = 0; i < 8; i++) {
        int x = pos.first + dirs[i][0];
        int y = pos.second + dirs[i][1];
        if (0 <= x && x < 8 && 0 <= y && y  < 8) {
            moves.push_back({x, y});
        }
    }
    return moves;
}

vector<pair<int, int>> chessboard::move_bishop(pair<int, int> pos) {
    vector<pair<int, int>> moves;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i + j == pos.first + pos.second || i - j == pos.first - pos.second) {
                moves.push_back({i, j});
            }
        }
    }
    return moves;
}

vector<pair<int, int>> chessboard::move_rook(pair<int, int> pos) {
    vector<pair<int, int>> moves;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == pos.first || j == pos.second) {
                moves.push_back({i, j});
            }
        }
    }
    return moves;
}

vector<pair<int, int>> chessboard::move_queen(pair<int, int> pos) {
    vector<pair<int, int>> moves;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == pos.first || j == pos.second || i + j == pos.first + pos.second || i - j == pos.first - pos.second) {
                moves.push_back({i, j});
            }
        }
    }
    return moves;
}

vector<pair<int, int>> chessboard::move_king(pair<int, int> pos) {
    vector<pair<int, int>> moves;
    int dirs[8][2] = {{1, 0},{1, 1},{0, 1},{-1, 1},{-1, 0},{-1, -1},{0, -1},{1, -1}};
    for (int i = 0; i < 8; i++) {
        int x = pos.first + dirs[i][0];
        int y = pos.second + dirs[i][1];
        if (0 <= x && x < 8 && 0 <= y && y  < 8) {
            moves.push_back({x, y});
        }
    }

    return moves;
}

vector<int> valid_moves() {
    vector<int> moves;
    return moves;
}

int main() {
    chessboard cb;
    //draw_chess_board();
    cb.draw_board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    //cb.draw_board("r1bk3r/p2pBpNp/n4n2/1p1NP2P/6P1/3P4/P1P1K3/q5b1");
    vector<pair<int, int>> pawns = cb.move_pawn({6, 4});
    for (int i = 0; i < pawns.size(); i++)
        cout << pawns[i].first << ", " << pawns[i].second << endl;
    return 0;
}