#ifndef PIECES_H
#define PIECES_H
#include <map>

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

class Moveset {
    public:
        Moveset(const int num_moves_in, const int* x_moves_in, const int* y_moves_in);
        const int num_moves;
        const int* x_moves;
        const int* y_moves;
};





const int pawn_xmoves[] = {0, 0, 1, -1};
const int pawn_ymoves[] = {1, 2, 1, 1}; 

const int rook_xmoves[] = {1, -1, 0, 0};
const int rook_ymoves[] = {0, 0, 1, -1}; 

const int knight_xmoves[] = {2, -2, 1, -1, -2, -2, 1, -1};
const int knight_ymoves[] = {1, 1, 2, 2, -1, -1, -2, -2};

const int bishop_xmoves[] = {1, 1, -1, -1};
const int bishop_ymoves[] = {1, -1, 1, -1};

const int queen_xmoves[] = {1, 1, -1, -1, 1, -1, 0, 0};
const int queen_ymoves[] = {1, -1, 1, -1, 0, 0, 1, -1}; 

const int king_xmoves[] = {1, 1, -1, -1, 1, -1, 0, 0};
const int king_ymoves[] = {1, -1, 1, -1, 0, 0, 1, -1};

const Moveset pawn_moves(4, pawn_xmoves, pawn_ymoves);
const Moveset rook_moves(4, rook_xmoves, rook_ymoves);
const Moveset knight_moves(8, knight_xmoves, knight_ymoves);
const Moveset bishop_moves(4, bishop_xmoves, bishop_ymoves);
const Moveset queen_moves(8, queen_xmoves, queen_ymoves);
const Moveset king_moves(8, king_xmoves, king_ymoves);


const std::map<const int, const Moveset> movesets = {
    {pawn, pawn_moves }, {rook, rook_moves }, {knight, knight_moves }, {bishop, bishop_moves}, {queen, queen_moves}, {king, king_moves}
};


#endif