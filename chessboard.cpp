#include <iostream>
#include <string>

using namespace std;

string letters = "abcdefgh";

void draw_chess_board() {
    bool light_dark_square = 0;
    for (int rank = 0; rank < 8; rank++) {
        light_dark_square = !light_dark_square;
        for (int file = 0; file < 8; file++) {
            cout << "[" << letters[file] << 8-rank << "]";
            // if (light_dark_square) {
            //     //cout << "[d] ";
            //     light_dark_square = 0;
            // }
            // else {
            //     //cout << "[l] ";
            //     light_dark_square = 1;
            // }
        }
        cout << endl;
    }
}

// empty board = [
//         ['d', 'l', 'd', 'l', 'd', 'l', 'd', 'l'],
//         ['l', 'd', 'l', 'd', 'l', 'd', 'l', 'd'],
//         ['d', 'l', 'd', 'l', 'd', 'l', 'd', 'l'],
//         ['l', 'd', 'l', 'd', 'l', 'd', 'l', 'd'],
//         ['d', 'l', 'd', 'l', 'd', 'l', 'd', 'l'],
//         ['l', 'd', 'l', 'd', 'l', 'd', 'l', 'd'],
//         ['d', 'l', 'd', 'l', 'd', 'l', 'd', 'l'],
//         ['l', 'd', 'l', 'd', 'l', 'd', 'l', 'd'],
//         ]

int main() {
    draw_chess_board();
    return 0;
}