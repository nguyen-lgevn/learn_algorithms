#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>

namespace games {

class Sudoku {
public:
    void set_sudoku(std::vector<std::vector<int>> sudoku);
    void printGrid();
    bool solve_sudoku();
    static Sudoku& getInstance();

private:
    Sudoku();
    bool find_unassigned_cell(int& row, int& col);
    bool is_used_in_row(int row, int num);
    bool is_used_in_col(int col, int num);
    bool is_used_in_box(int box_row, int box_col, int num);
    bool is_safe(int row, int col, int num);

    const int sudoku_size = 9;
    std::vector<std::vector<int>> m_sudoku;
};

} // namespace games

#endif
