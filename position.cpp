#include "position.hpp"
using namespace std;
Position::Position():
score(0), wk_castle(true), double_move_row(8), wq_castle(true), bk_castle(true), bq_castle(true), en_passant_col(-1), king_passant(false) 
{
    board=unique_ptr<Board>(new Board());
}

shared_ptr<vector<Move>> Position::gen_moves(int row, int col) {
    shared_ptr<vector<Move>> move_list(new vector<Move>());
    for (int i = row; i < board_end; ++i) {
        for (int j = col; j < board_end; ++j) {
            if (board->colors[i][j] == white) {
                switch (board->pieces[i][j]) {
                    case pawn:
                        pawn_moves(move_list, i, j);
                        break;
                    case knight:
                        knight_moves(move_list, i, j);
                        break;
                    case king:
                        king_moves(move_list, i, j);
                        break;
                    default:
                        sliding_moves(move_list, i, j);
                }
            }
        }
    }
    return move_list; 
}

void Position::sliding_moves(shared_ptr<vector<Move>> move_list, int row, int col) {
    const int piece_type = board->pieces[row][col];
    Moveset possible_moves = movesets.at(piece_type);
    int x_distance, y_distance;
    const int* x_moves = possible_moves.x_moves;
    const int* y_moves = possible_moves.y_moves;

    for (int i = 0; i < possible_moves.num_moves; i++) {
        x_distance = x_moves[i];
        y_distance = y_moves[i];
        while (board->colors[row + y_distance][col + x_distance] != null && board->colors[row + y_distance][col + x_distance] != white) {
            move_list->push_back(Move(row, col, row + y_distance, col + x_distance));
            if (board->colors[row + y_distance][col + x_distance] == black) {
                break;
            }
            x_distance += x_moves[i];
            y_distance += y_moves[i];

        }
    }

}
void Position::pawn_moves(shared_ptr<vector<Move>> move_list, int row, int col) {
    if (board->pieces[row - 1][col] == blank) {
        move_list->push_back(Move(row, col, row - 1, col));
        if (board->pieces[row - 2][col] == blank && row == double_move_row) {
            move_list->push_back(Move(row, col, row - 2, col));
        }
    }
    int capture_left = board->colors[row - 1][col - 1];
    int capture_right = board->colors[row - 1][col + 1];
    bool en_passant_right = en_passant_col == col + 1;
    bool en_passant_left = en_passant_col == col - 1;

    if (capture_left == black || (capture_left == blank && en_passant_left)) {
        move_list->push_back(Move(row, col, row - 1, col - 1));
    }
    if (capture_right == black || capture_left == blank && en_passant_right) {
        move_list->push_back(Move(row, col, row - 1, col + 1));
    }
}
void Position::knight_moves(shared_ptr<vector<Move>> move_list, int row, int col) {
    Moveset knight_moves = movesets.at(knight);
    const int* x_moves = knight_moves.x_moves;
    const int* y_moves = knight_moves.y_moves;

    for (int i = 0; i < 8; i++) {
        int move_x = col + x_moves[i];
        int move_y = row + y_moves[i];

        if (board->colors[move_y][move_x] == black || board->colors[move_y][move_x] == blank) {
            move_list->push_back(Move(row, col, move_y, move_x));
        }
    }
}
void Position::king_moves(shared_ptr<vector<Move>> move_list, int row, int col) {
    Moveset king_moves = movesets.at(king);
    const int* x_moves = king_moves.x_moves;
    const int* y_moves = king_moves.y_moves;

    for (int i = 0; i < 8; i++) {
        int move_x = col + x_moves[i];
        int move_y = row + y_moves[i];

        if (board->colors[move_y][move_x] == black || board->colors[move_y][move_x] == blank) {
            move_list->push_back(Move(row, col, move_y, move_x));
        }
    }
    if (wk_castle) {
        if (board->pieces[row][col + 1] == blank && board->pieces[row][col + 2] == blank) {
            move_list->push_back(Move(row, col, row, col + 3));
        }
    }
    if (wq_castle) {
        if (board->pieces[row][col - 1] == blank && board->pieces[row][col - 2] == blank && board->pieces[row][col - 3]) {
            move_list->push_back(Move(row, col, row, col - 4));
        }
    }
}
bool Position::legal_move(Move m) {

}                               

void Position::make_move(Move m) {

}                               

void Position::print() {
    board->print_board();
}