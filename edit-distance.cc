// https://leetcode.com/problems/edit-distance

class Solution {
private:
    /*int EditDist(const string& s1, const string& s2, int N1, int N2) {
        if (N1 == 0 && N2 == 0) {
            return 0;
        }
        
        if (N1 == 0) {
            return N2;
        }
        
        if (N2 == 0) {
            return N1;
        }
        
        if (s1[N1 - 1] == s2[N2 - 1]) {
            return EditDist(s1, s2, N1 - 1, N2 - 1);
        }
        
        return 1 + std::min(EditDist(s1, s2, N1 - 1, N2),
                            std::min(EditDist(s1, s2, N1, N2 - 1),
                                     EditDist(s1, s2, N1 - 1, N2 - 1)));
    }*/
    
public:
    int minDistance(string word1, string word2) {
        //return EditDist(word1, word2, word1.size(), word2.size());
        
        const auto& s1 = word1;
        const auto& s2 = word2;
        
        const auto N1 = s1.size();
        const auto N2 = s2.size();
        
        if (N1 == 0 && N2 == 0) {
            return 0;
        }
        
        if (N1 == 0) {
            return N2;
        }
        
        if (N2 == 0) {
            return N1;
        }
        
        auto dp = std::vector<std::vector<int>>(N1 + 1, std::vector<int>(N2 + 1));
        
        for (auto i = 0; i <= N1; ++i) {
            for (auto j = 0; j <= N2; ++j) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + std::min(dp[i - 1][j - 1], std::min(dp[i][j - 1], dp[i - 1][j]));
                }
            }
        }
        
        return dp[N1][N2];
    }
};
