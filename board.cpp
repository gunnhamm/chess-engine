#include "board.hpp"
#include <iostream>
void Board::print_board() {
    for (int i = 2; i < 10; ++i) {
        for (int j = 2; j < 10; ++j) {
            char piece = '-';
            switch (pieces[i][j]) {
                case pawn:
                    piece = 'p';
                    break;
                case rook:
                    piece = 'r';
                    break;
                case knight:
                    piece = 'n';
                    break;
                case bishop:
                    piece = 'b';
                    break;
                case queen:
                    piece = 'q';
                    break;
                case king:
                    piece = 'k';
            }
            if (piece != '-' && colors[i][j] == white) {
                piece -= 32;
            }
            std::cout << piece << ' ';
        }
        std::cout << std::endl;
    }
}
std::vector<Move> Board::gen_moves() {
    
    for (int i = 2; i < 10; ++i) {
        for (int j = 2; j < 10; ++j) {
            if (colors[i][j] == white) {
                switch (pieces[i][j]) {
                    case pawn:
                        piece = 'p';
                        break;
                    case rook:
                        piece = 'r';
                        break;
                    case knight:
                        piece = 'n';
                        break;
                    case bishop:
                        piece = 'b';
                        break;
                    case queen:
                        piece = 'q';
                        break;
                    case king:
                        piece = 'k';
                }
            }
        }
    }
}

int main() {
    Board b;
    b.print_board();
    return 0;
}