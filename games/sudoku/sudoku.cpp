#include "sudoku.h"
#include <iostream>
#include <iomanip>

using namespace games;

Sudoku::Sudoku()
{

}
        
Sudoku& Sudoku::getInstance()
{
    static Sudoku instance;
    return instance;
}

void Sudoku::set_sudoku(std::vector<std::vector<int>> sudoku)
{
    m_sudoku = sudoku;
}

void Sudoku::printGrid()
{
    std::cout << __FUNCTION__ << std::endl;
    for (int row = 0; row < sudoku_size; row++)
    {
        for (int col = 0; col < sudoku_size; col++)
        {
            std::cout << std::setw(2) << m_sudoku.at(row).at(col); 
        }
        std::cout << std::endl;
    }
}


bool Sudoku::solve_sudoku()
{
    std::cout << __FUNCTION__ << std::endl;
    int row, col;
    if (!find_unassigned_cell(row, col))
            return true;
    for (int num = 1; num <=9; num++)
    {
        if (is_safe(row, col, num))
        {
            m_sudoku[row][col] = num;
            if (solve_sudoku())
                return true;
            m_sudoku[row][col] = 0;
        }
    }
    return false;
}
    
bool Sudoku::find_unassigned_cell(int& row, int& col)
{
    std::cout << __FUNCTION__ << std::endl;
    for (row = 0; row < sudoku_size; row ++)
        for (col = 0; col < sudoku_size; col++)
            if (m_sudoku.at(row).at(col) == 0)
            {
                std::cout << __FUNCTION__ << ": " << row << " " << col << std::endl;
                return true;
            }
    return false;
}
    
bool Sudoku::is_used_in_row(int row, int num)
{
    std::cout << __FUNCTION__ << std::endl;
    for (int col = 0; col < sudoku_size; col++)
    {
        if (m_sudoku.at(row).at(col) == num)
            return true;
    }
    return false;
}
    
bool Sudoku::is_used_in_col(int col, int num)
{
    std::cout << __FUNCTION__ << std::endl;
    for (int row = 0; row < sudoku_size; row++)
    {
        if (m_sudoku.at(row).at(col) == num)
            return true;
    }
    return false;
}

    
bool Sudoku::is_used_in_box(int box_row, int box_col, int num)
{
    std::cout << __FUNCTION__ << std::endl;
    for (int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            if (m_sudoku.at(row + box_row).at(col + box_col) == num)
                return true;
        }
    }
    return false;
}
    
bool Sudoku::is_safe(int row, int col, int num)
{
    return !is_used_in_row(row, num) && !is_used_in_col(col, num) && !is_used_in_box(row - row%3, col - col%3, num) && (m_sudoku.at(row).at(col) == 0);
}
