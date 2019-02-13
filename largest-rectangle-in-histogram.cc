// https://leetcode.com/problems/largest-rectangle-in-histogram
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        using li = long int;
        const li N = heights.size();
        
        if (N == 0) {
            return 0;
        }
        
        li max_area = 0;
        auto s = std::stack<li>{};
        
        for (li idx = 0; idx < N; ++idx) {
            li cur_height = heights[idx];
            while (!s.empty() && cur_height <= heights[s.top()]) {
                li tp = s.top();
                s.pop();
                    
                auto cur_area = heights[tp] * (s.empty() ? (idx) : (idx - s.top()  - 1));
                max_area = std::max(max_area, cur_area);
            }
            s.push(idx);
        }
        
        return max_area;
    }
};
