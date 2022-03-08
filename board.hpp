#include "move.hpp"
#include <vector>
const int null = 0;
const int blank = 1;
const int black = 2;
const int white = 3;
const int pawn = 4;
const int rook = 5;
const int knight = 6;
const int bishop = 7;
const int queen = 8;
const int king = 9;


class Board {
    public:
        std::vector<Move> gen_moves();
        inline void pawn_moves(std::vector<Move> move_list);
        inline void rook_moves(std::vector<Move> move_list);
        inline void knight_moves(std::vector<Move> move_list);
        inline void bishop_moves(std::vector<Move> move_list);
        inline void queen_moves(std::vector<Move> move_list);
        inline void king_moves(std::vector<Move> move_list);
        void print_board();


    private:
        int colors[12][12] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0},
            {0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0},
            {0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0},
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
