#ifndef BOARD_H
#define BOARD_H

#include "pieces.hpp"
#include <vector>
#include <memory>
#include <iostream>

class Board {
    public:
        void flip();
        void print_board();
        Board();
        void put(int piece, int color, int row, int col);
        void clear();
        char colors[12][12]; /*= {
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
        };*/

        char pieces[12][12];/* = {
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
        };*/
};

class Move {
    public:
        Move(int start_row, int start_col, int end_row, int end_col);
        int start_row();
        int start_col();
        int end_row();
        int end_col();

    private:
        short encoding;
};

std::ostream &operator<<(std::ostream &os, Move m);



#endif