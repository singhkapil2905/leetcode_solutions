// https://leetcode.com/problems/n-queens

class Solution {
private:
    using vvs = std::vector<std::vector<std::string>>;
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
    
    void Queens(std::vector<int>& placed, int col, int n, vvs& ans) {
        if (col == n) {
            auto res_vec = std::vector<string>{};
            for (auto idx = 0; idx < n; ++idx) {
                auto tmp = std::string(n, '.');
                tmp[placed[idx]] = 'Q';
                res_vec.push_back(tmp);
            }
            ans.push_back(res_vec);
            return;
        }
        
        for (auto idx = 0; idx < n; ++idx) {
            if (IsValid(placed, col, idx)) {
                placed[col] = idx;
                Queens(placed, col + 1, n, ans);
                placed[col] = INT_MIN;
            }
        }
        return;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 1) {
            return {{"Q"}};
        }
        
        if (n < 4) {
            return {};
        }
        
        auto placed = std::vector<int>(n, INT_MIN);
        auto ans = vvs{};
        Queens(placed, 0, n, ans);
        return ans;
    }
};
