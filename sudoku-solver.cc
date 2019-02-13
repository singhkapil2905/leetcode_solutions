// https://leetcode.com/problems/sudoku-solver/

class Solution {
private:
    using Board = vector<vector<char>>;
    static const auto row_per_cube = 3;
    static const auto col_per_cube = 3;
    static const auto row_len = 9;
    static const auto col_len = 9;
    
    bool IsValid(Board& board, int m, int n, char ch) {
        auto base_row = (m / row_per_cube) * row_per_cube;
        auto base_col = (n / col_per_cube) * col_per_cube;
        
        auto i = base_row;
        auto j = base_col;
        
        for (auto p = 0; p < row_per_cube; ++p) {
            for (auto q = 0; q < col_per_cube; ++q) {
                if (board[i + p][j + q] == ch) {
                    return false;
                }
            }
        }
        
        for (auto i = 0; i < col_len; ++i) {
            if (board[m][i] == ch) {
                return false;
            }
        }
        
        for (auto j = 0; j < row_len; ++j) {
            if (board[j][n] == ch) {
                return false;
            }
        }
        
        return true;
    }
    
public:
    bool SolvesSudoku(Board& board, int m , int n, int M, int N) {
        if (m == M || n == N) {
            return true;
        }
        
        auto next_m = (n == N - 1) ? m + 1 : m;
        auto next_n = (n == N - 1) ? 0 : n + 1;
        
        if (board[m][n] != '.') {
            return SolvesSudoku(board, next_m, next_n, M, N);
        } else {
            for (auto ch : {'1', '2', '3', '4', '5', '6', '7', '8', '9'}) {
                if (IsValid(board, m, n, ch)) {
                    board[m][n]  = ch;
                    
                    if (m == M - 1 && n == N - 1) {
                        return true;
                    }
                    
                    if (SolvesSudoku(board, next_m, next_n, M, N)) {
                        return true;
                    }
                }
                board[m][n] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        auto M = int{board.size()};
        if (M == 0) {
            return;
        }
        
        auto N = int{board.at(0).size()};
        
        if (N == 0) {
            return;
        }
        
        SolvesSudoku(board, 0, 0, M, N);
    }
};
