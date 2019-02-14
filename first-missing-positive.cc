// https://leetcode.com/problems/first-missing-positive

class Solution {    
public:
    int firstMissingPositive(vector<int>& nums) {
        const auto N = int{nums.size()};
        
        for (auto idx = 0; idx < N; ++idx) {
            const auto cur = nums.at(idx);
            
            if (cur <= 0 || cur > N || cur == idx + 1 || nums.at(idx) == nums.at(cur - 1)) {
                continue;
            }
            
            std::swap(nums.at(idx), nums.at(cur - 1));
            
            if (nums.at(idx) > 0 && nums.at(idx) <= N) {
                --idx;
            }
        }
        
        for (auto idx = 0; idx < N; ++idx) {
            if (nums.at(idx) != idx + 1) {
                return idx + 1;
            }
        }
        return N + 1;
    }
};
