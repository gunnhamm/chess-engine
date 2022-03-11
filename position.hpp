#include "board.hpp"
#include "pieces.hpp"
class Position {
    public:
        std::shared_ptr<std::vector<Move>> gen_moves(int row, int col);
        inline void piece_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col);

        
    private:
        std::unique_ptr<Board> board;
        int score;

        bool wk_castle;
        bool wq_castle;

        bool bk_castle;
        bool bq_castle;

        bool en_passant;
        bool king_passant;
};