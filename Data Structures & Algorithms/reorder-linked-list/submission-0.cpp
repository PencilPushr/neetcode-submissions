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
    void reorderList(ListNode* head) 
    {
        // Step 1: Identify middle of list
        ListNode* slow = head; // THIS WILL BE OUR MIDDLE
        ListNode* fast = head->next; // Must make this head + 1;

        while (fast != nullptr && fast->next != nullptr )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* secondHalfPtr = slow->next;
        
        // Step 2: Reverse Linkedlist from slow pointer to end of list
        slow->next = nullptr;
        ListNode* prev = nullptr;

        while (secondHalfPtr != nullptr)
        {
            ListNode* temp = secondHalfPtr->next;
            secondHalfPtr->next = prev;
            prev = secondHalfPtr;
            secondHalfPtr = temp;
        }

        // Step 3: Two pointers merge the lists
        ListNode* start = head;
        secondHalfPtr = prev;
        while (secondHalfPtr != nullptr)
        {
            ListNode* tmp1 = start->next;
            ListNode* tmp2 = secondHalfPtr->next;
            start->next = secondHalfPtr;
            secondHalfPtr->next = tmp1;
            start = tmp1;
            secondHalfPtr = tmp2;
        }
    }
};
