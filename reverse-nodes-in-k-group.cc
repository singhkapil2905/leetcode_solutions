// https://leetcode.com/problems/reverse-nodes-in-k-group

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* Reverse(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* prev{nullptr};
        ListNode* cur{head};
        ListNode* next{head->next};
        
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* cur_head{head};
        ListNode* next_head{nullptr};
        ListNode* last{nullptr};
        ListNode* tmp{head};
        ListNode* new_head{nullptr};
        
        for (auto i = int{0}; i < k - 1 && tmp; ++i) {
            tmp = tmp->next;
        }
        
        if (!tmp) {
            return head;
        }
        
        cur_head = head;
        
        do {
            next_head = tmp ? tmp->next : nullptr;
            if (tmp) {
                tmp->next = nullptr;
            }
            
            if (!new_head) {
                new_head = Reverse(cur_head);
            } else {
                last->next = Reverse(cur_head);
            }
            
            last = cur_head;
            tmp = next_head;
            
            for (auto i = int{0}; i < k - 1 && tmp; ++i) {
                tmp = tmp->next;
            }
            
            if (!tmp) {
                last->next = next_head;
                return new_head;
            }
            
            cur_head = next_head;
        } while(cur_head != nullptr);
        
        return new_head;
    }
};
