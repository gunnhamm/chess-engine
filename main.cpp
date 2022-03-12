#include "position.hpp"
#include "board.hpp"
#include "pieces.hpp"
using namespace std;
int main(int argc, char** argv) {
    Position p;
    shared_ptr<vector<Move>> list = p.gen_moves(0, 0);
    for (auto it = list->begin(); it != list->end(); it++) {
        cout << *it << endl;
    }
    p.print();
    return 0;
}