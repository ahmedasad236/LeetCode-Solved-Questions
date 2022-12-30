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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !(head->next)) return nullptr;
        
        ListNode* curr = head;
        ListNode* curr2 = head;
        while(curr2 && curr2->next) {
            curr2 = curr2->next->next;
            curr = curr->next;
            if(!curr2 || !curr2->next) return nullptr; 
            
            if(curr == curr2) break;

        }
        if(!curr2 || !curr2->next) return nullptr;
        while(head != curr)
            head = head->next, curr = curr->next;
        return head;
    }
};