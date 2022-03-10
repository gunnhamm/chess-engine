#ifndef PIECES_H
#define PIECES_H
class Moveset {
    public:
        Moveset(int num_moves_in, int* x_moves_in, int* y_moves_in);
        int num_moves;
        int* x_moves;
        int* y_moves;
};
Moveset::Moveset(int num_moves_in, int* x_moves_in, int* y_moves_in): 
    num_moves(num_moves_in), x_moves(x_moves_in), y_moves(y_moves_in) {};

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

const int pawn_xmoves[] = {0, 0, 1, -1};
const int pawn_ymoves[] = {1, 2, 1, 1}; 

const int rook_xmoves[] = {1, -1, 0, 0};
const int rook_ymoves[] = {0, 0, 1, -1}; 

const int knight_xmoves[] = {2, -2, 1, -1, -2, -2, -1, -1};
const int knight_ymoves[] = {1, 1, 2, 2, -1, -1, -2, -2};

const int bishop_xmoves[] = {1, 1, -1, -1};
const int bishop_ymoves[] = {1, -1, 1, -1};

const int queen_xmoves[] = {1, 1, -1, -1, 1, -1, 0, 0};
const int queen_ymoves[] = {1, -1, 1, -1, 0, 0, 1, -1}; 

const int king_xmoves[] = {1, 1, -1, -1, 1, -1, 0, 0};
const int king_ymoves[] = {1, -1, 1, -1, 0, 0, 1, -1};

const Moveset pawn_moves()

#endif