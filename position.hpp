#include "board.hpp"
#include "pieces.hpp"
class Position {
    public:
        std::shared_ptr<std::vector<Move>> gen_moves(int row, int col);
        void sliding_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col);
        void pawn_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col);
        void knight_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col);
        void king_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col);
        Position();
        void print();


        
    private:
        std::unique_ptr<Board> board;
        int score;

        bool wk_castle;
        bool wq_castle;

        bool bk_castle;
        bool bq_castle;

        int en_passant_col;

        bool king_passant;
};