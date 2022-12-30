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
    ListNode* middleNode(ListNode* head) {
        if(!head) return head;
        int size = 0;
        ListNode* curr = head;
        while(curr) curr = curr->next, size++;
        curr = head;
        int mid = size / 2, i = 0;
        while(curr) {
            if(i == mid) return curr;
            curr = curr->next;
            i++;
        }
        return nullptr;
    }
};