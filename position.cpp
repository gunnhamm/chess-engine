#include "position.hpp"

Position::Position():
score(0), wk_castle(false), wq_castle(false), bk_castle(false), bq_castle(false), en_passant_col(-1), king_passant(false)
{
    board=std::unique_ptr<Board>(new Board());
}

std::shared_ptr<std::vector<Move>> Position::gen_moves(int row, int col) {
    std::shared_ptr<std::vector<Move>> move_list(new std::vector<Move>());
    for (int i = row; i < board_end; ++i) {
        for (int j = col; j < board_end; ++j) {
            if (board->colors[i][j] == white) {
                switch (board->pieces[i][j]) {
                    case pawn:
                        pawn_moves(move_list, i, j);
                    case knight:
                        knight_moves(move_list, i, j);
                    case king:
                        king_moves(move_list, i, j);
                    default:
                        sliding_moves(move_list, i, j);
                }
            }
        }
    }
    return move_list; 
}

void Position::sliding_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col) {
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
            if (board->pieces[row + y_distance][col + x_distance] == black) {
                break;
            }
            x_distance += x_moves[i];
            y_distance += y_moves[i];

        }
    }

}
void Position::pawn_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col) {
    if (board->pieces[row - 1][col] == blank) {
        move_list->push_back(Move(row, col, row - 1, col));
        if (board->pieces[row - 2][col] == blank) {
            move_list->push_back(Move(row, col, row - 2, col));
        }
    }
    int capture_left = board->pieces[row - 1][col - 1];
    int capture_right = board->pieces[row - 1][col + 1];
    bool en_passant_right = en_passant_col == col + 1;
    bool en_passant_left = en_passant_col == col - 1;

    if (capture_left == black || (capture_left == blank && en_passant_left)) {
        move_list->push_back(Move(row, col, row - 1, col - 1));
    }
    if (capture_right == black || capture_left == blank && en_passant_right) {
        move_list->push_back(Move(row, col, row - 1, col + 1));
    }
}
void Position::knight_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col) {
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
void Position::king_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col) {
    
}
