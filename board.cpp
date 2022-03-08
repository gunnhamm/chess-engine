#include "board.hpp"
using namespace std;
void Board::print_board() {
    for (int i = board_start; i < board_end; ++i) {
        for (int j = board_start; j < board_end; ++j) {
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
            cout << piece << ' ';
        }
        cout << endl;
    }
}
void Board::flip() {
    for (int i = board_start; i < board_end; ++i) {
        for (int j = board_start; j < board_end; ++j) {
            colors[i][j] *= -1;
        }
    }
}
vector<Move> Board::gen_moves() {
    shared_ptr<vector<Move>> moves(new vector<Move>());
    for (int i = board_start; i < board_end; ++i) {
        for (int j = board_start; j < board_end; ++j) {
            if (colors[i][j] == white) {
                switch (pieces[i][j]) {
                    case pawn:
                        pawn_moves(moves, i, j);
                        break;
                    case rook:
                        rook_moves(moves, i, j);
                        break;
                    case knight:
                        knight_moves(moves, i, j);
                        break;
                    case bishop:
                        bishop_moves(moves, i, j);
                        break;
                    case queen:
                        queen_moves(moves, i, j);
                        break;
                    case king:
                        king_moves(moves, i, j);

                }
            }
        }
    }
}
inline void bishop_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col) {
    
}
int main() {
    Board b;
    b.print_board();
    return 0;
}