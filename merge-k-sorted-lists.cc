// https://leetcode.com/problems/merge-k-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<queue>


class Solution {
    class MyComparator {
        public:
            bool operator () (const ListNode* const lhs, const ListNode* const rhs) {
                return lhs->val > rhs->val;
            }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const auto N = lists.size();
        
        if (N == 0) {
            return nullptr;
        }
        
        std::priority_queue<ListNode*, std::vector<ListNode*>, MyComparator> q;
        
        for (auto& list_head : lists) {
            if (list_head) {
                q.push(list_head);
            }
        }
        
        const auto dummy = new ListNode(0);
        auto last = dummy;
        
        while (!q.empty()) {
            auto tp = q.top();
            q.pop();
            if (tp->next) {
                q.push(tp->next);
            }
            last->next = tp;
            last = last->next;
        }
        
        return dummy->next;
    }
};
