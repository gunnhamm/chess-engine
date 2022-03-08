#include "move.hpp"
#include <vector>
#include <memory>
#include <iostream>

const int black = -2;
const int null = 0;
const int blank = 1;
const int white = 2;

const int pawn = 4;
const int rook = 5;
const int knight = 6;
const int bishop = 7;
const int queen = 8;
const int king = 9;

const int board_start = 2;
const int board_end = 10;


class Board {
    public:
        std::vector<Move> gen_moves();
        inline void pawn_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col);
        inline void rook_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col));
        inline void knight_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col);
        inline void bishop_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col);
        inline void queen_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col);
        inline void king_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col);
        void flip();
        void print_board();


    private:
        int colors[12][12] = {
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
        };

        int pieces[12][12] = {
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
        };
};
