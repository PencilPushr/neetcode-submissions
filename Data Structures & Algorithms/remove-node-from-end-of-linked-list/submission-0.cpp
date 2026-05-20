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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {

        ListNode* start = head;

        // Get length of list
        int counter = 0;
        while (start != nullptr)
        {
            start = start->next;
            counter++;
        }

        counter = counter - n; // WE ARE USING 0 INDEXING, USE -1 !!!
        if (counter == 0)
        {
            return head->next;
        }

        counter--;
        start = head;
        while (counter != 0)
        {
            start = start->next;
            counter--;
        }

        start->next = start->next->next;

        return head;       

    }
};
