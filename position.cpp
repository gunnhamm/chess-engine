inline void Board::bishop_moves(std::shared_ptr<std::vector<Move>> move_list, int row, int col) {
    int x_moves[] = {1, 1, -1, -1};
    int y_moves[] = {1, -1, 1, -1};
    int x_distance, y_distance;

    for (int i = 0; i < 4; i++) {
        x_distance = x_moves[i];
        y_distance = y_moves[i];
        while (colors[row + y_distance][col + x_distance] != null && colors[row + y_distance][col + x_distance] != white) {
            move_list->push_back(Move(row, col, row + y_distance, col + x_distance));
            if (pieces[row + y_distance][col + x_distance] == black) {
                break;
            }
        }
    }

}