#include "move.hpp"
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
        Move pawn_moves();
        Move rook_moves();
        Move knight_moves();
        Move bishop_moves();
        Move queen_moves();
        Move king_moves();


    private:
        int colors[12][12];
        int pieces[12][12];
};
