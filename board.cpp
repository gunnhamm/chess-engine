#include "board.hpp"
using namespace std;

Board::Board():
    colors(
    {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, -2, -2, -2, -2, -2, -2, -2, -2, 0, 0},
            {0, 0, -2, -2, -2, -2, -2, -2, -2, -2, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0},
            {0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    }
    ),
    pieces(
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 5, 6, 7, 8, 9, 7, 6, 5, 0, 0},
        {0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0},
        {0, 0, 5, 6, 7, 8, 9, 7, 6, 5, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    }
    )
{}

void Board::print_board() {
    for (int i = board_start; i < board_end; ++i) {
        cout << 10 - i << " ";
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
    cout << "  ";
    for (char c = 'a'; c <= 'h'; c++) {
        cout <<  c << " ";
    }
    cout << endl;
}
void Board::flip() {
    for (int i = board_start; i < board_end; ++i) {
        for (int j = board_start; j < board_end; ++j) {
            colors[i][j] *= -1;
        }
    }
}
void Board::put(int piece, int color, int row, int col) {
    pieces[row + 2][col + 2] = piece;
    colors[row + 2][col + 2] = color;
}
void Board::clear() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            put(blank, blank, i, j);
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
    start_row-=2;
    start_col-=2;
    end_row-=2;
    end_col-=2;

    encoding = 0 | start_row << 9 | start_col << 6 | end_row << 3 | end_col;
}
ostream &operator<<(ostream &os, Move m) {
    os << char(m.start_col() + 'a') << 8 - m.start_row() << char(m.end_col() + 'a') << 8 - m.end_row();
    return os;
}