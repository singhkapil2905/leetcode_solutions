// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        const auto N = nums.size();
        
        if (N < 2) {
            return 0;
        }
        
        auto jumps = int{1};
        auto cur_end = int{0}, max_end = int{0};
        
        for (auto idx = 0; idx <= cur_end; ++idx) {
            max_end = std::max(max_end, idx + nums.at(idx));
            
            if (max_end >= N - 1) {
                return jumps;
            }
            
            if (idx == cur_end) {
                cur_end = max_end;
                ++jumps;
            }
        }
        
        return INT_MAX;
    }
};
