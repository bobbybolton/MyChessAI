#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#define ROWS 8
#define COLS 8


#include <iostream>
#include <vector>

struct piece {
    char name;
    double value;
    std::pair<int, int> pos;
    bool color;
    bool inplay;
};

struct knight {
    double value;
};

class chessboard{
    piece board[ROWS][COLS];
    piece pieces[32];
    public:
    void draw_board(std::string fen);
    std::vector<std::pair<int, int>> move_pawn(std::pair<int, int> pos);
    std::vector<std::pair<int, int>> move_knight(std::pair<int, int> pos);
    std::vector<std::pair<int, int>> move_bishop(std::pair<int, int> pos);
    std::vector<std::pair<int, int>> move_rook(std::pair<int, int> pos);
    std::vector<std::pair<int, int>> move_queen(std::pair<int, int> pos);
    std::vector<std::pair<int, int>> move_king(std::pair<int, int> pos);
    std::vector<int> valid_moves();
};


#endif