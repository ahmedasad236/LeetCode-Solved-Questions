/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* curr = res;
        int carry = 0;
        while(l1 || l2) {
            int val = 0;
            if(l1) val += l1->val;
            if(l2) val += l2->val;
            val += carry;
            carry = val / 10;
            val %= 10;
            curr->val = val;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            if(l1 || l2 || carry) curr->next = new ListNode();
            curr = curr->next;
        }
        if(carry) curr->val = carry;
        return res;
        
        
    }
};