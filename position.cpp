#include "position.hpp"
inline void Position::piece_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col) {
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
        }
    }

}