#include "position.hpp"
#include "board.hpp"
#include "pieces.hpp"
using namespace std;
int main(int argc, char** argv) {
    Position p;
    p.board->clear();
    p.board->put(king, white, 7, 4);
    p.board->put(rook, white, 7, 7);
    p.board->put(rook, white, 7, 0);
    
    shared_ptr<vector<Move>> list = p.gen_moves(0, 0);
    for (auto it = list->begin(); it != list->end(); it++) {
        cout << *it << endl;
    }
    p.print();
    return 0;
}