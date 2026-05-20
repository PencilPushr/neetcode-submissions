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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = nullptr;
        for(auto i = head; i;)
        {
            // Save the pointer to the next
            ListNode* temp = i->next;
            // Set swap pointer to point to prev
            i->next = prev;
            // Set prev to us
            prev = i;
            // Restore state to move to next
            i = temp;
        }

        return prev;
    }
};
