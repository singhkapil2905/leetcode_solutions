// https://leetcode.com/problems/n-queens-ii

class Solution {
private:
    bool IsValid(const std::vector<int>& placed, int col, int p_index) {
        auto n = placed.size();
        auto diag_up = p_index - 1;
        auto diag_down = p_index + 1;
        for (auto idx = col - 1; idx >= 0; --idx) {
            if (placed[idx] == p_index) {
                return false;
            }
            
            if (p_index > 0 && placed[idx] == diag_up) {
                return false;
            }
            
            if (p_index < n - 1 && placed[idx] == diag_down) {
                return false;
            }
            
            --diag_up;
            ++diag_down;
        }
        
        return true;
    }
    
    int Queens(std::vector<int>& placed, int col, int n) {
        if (col == n) {            
            return 1;
        }
        
        auto ways = 0;
        for (auto idx = 0; idx < n; ++idx) {
            if (IsValid(placed, col, idx)) {
                placed[col] = idx;
                ways += Queens(placed, col + 1, n);
                placed[col] = INT_MIN;
            }
        }
        return ways;
    }
    
public:
    int totalNQueens(int n) {
        if (n == 1) {
            return 1;
        }
        
        if (n < 4) {
            return 0;
        }
        
        auto placed = std::vector<int>(n, INT_MIN);
        
        return Queens(placed, 0, n);
    }
};
