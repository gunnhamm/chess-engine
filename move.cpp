#include "move.hpp"
int Move::start_row() {
    return (encoding & 0x003f) / 8;
}
int Move::start_col() {
    return (encoding & 0x003f) % 8;
}
int Move::end_row() {
    return (encoding & 0x0fc0) / 8;
}
int Move::end_col() {
    return (encoding & 0x0fc0) % 8;
}