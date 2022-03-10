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
shared_ptr<vector<Move>> Board::gen_moves(int row, int col) {
    shared_ptr<vector<Move>> moves(new vector<Move>());
    for (int i = row; i < board_end; ++i) {
        for (int j = col; j < board_end; ++j) {
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
            return moves;
        }
    }
}

int Move::end_col() {
    return (encoding & 0x0007);
}
int Move::end_row() {
    return (encoding & 0x0038) >> 3;
}
int Move::start_col() {
    return (encoding & 0x01c0) >> 6;
}
int Move::start_row() {
    return (encoding & 0x0e00) >> 9;
}
Move::Move(int start_row, int start_col, int end_row, int end_col) {
    encoding = 0 | start_row << 9 | start_col << 6 | end_row << 3 | end_col;
}

int main() {
    Board b;
    b.print_board();
    return 0;
}