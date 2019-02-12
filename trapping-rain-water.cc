// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    using li = long int;
    int trap(vector<int>& height) {
        auto N = li{height.size()};
        
        if (N < 2) {
            return 0;
        }
        
        auto l_max = std::vector<li>(N, 0);
        auto r_max = std::vector<li>(N, 0);
        auto mx = li{height.at(0)};
        
        for (auto idx = 1; idx < N; ++idx) {
            auto cur_height = height.at(idx);
            
            l_max.at(idx) = mx;
            
            if (cur_height > mx) {
                mx = cur_height;
            }
        }
        
        mx = height.at(N - 1);
        
        for (auto idx = N - 2; idx >= 0; --idx) {
            auto cur_height = height.at(idx);
   
            r_max.at(idx) = mx;
            
            if (cur_height > mx) {
                mx = cur_height;
            }
        }
        
        
        auto res = 0;
        
        for (auto idx = 1; idx < N - 1; ++idx) {
            auto l_max_height = l_max.at(idx);
            auto r_max_height = r_max.at(idx);
            auto cur_height = height.at(idx);
            
            if (cur_height > l_max_height || cur_height > r_max_height
                || l_max_height == 0 || r_max_height == 0) {
                continue;
            }
            
            res += std::min(l_max_height, r_max_height) - cur_height;
        }
        
        return res;
    }
};
