// https://leetcode.com/problems/binary-tree-maximum-path-sum

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int MaxSumPath(TreeNode* root, int& mx) {
        if (!root) {
            return 0;
        }
        
        auto l_max = MaxSumPath(root->left, mx);
        auto r_max = MaxSumPath(root->right, mx);
        
        auto max_candidate = std::max(std::max(l_max, r_max) + root->val, root->val);
        
        auto max_candidate2 = std::max(l_max + r_max + root->val, max_candidate);
        mx = std::max(mx, max_candidate2);
        
        return max_candidate;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        auto mx = int{INT_MIN};
        
        MaxSumPath(root, mx);
        
        return mx;
    }
};
