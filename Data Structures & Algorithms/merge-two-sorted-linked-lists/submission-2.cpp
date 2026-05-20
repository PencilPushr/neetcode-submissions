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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        // This is what we actually build the pointer list
        ListNode dummy(0);
        ListNode* pNewList = &dummy;

        // Think of these as our eyes
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while( l1 && l2 )
        {
            // Update the new List and move eyes to next nodes conditionally
            if ( l1->val < l2->val )
            {
                pNewList->next = l1;
                l1 = l1->next;
            }
            else
            {
                pNewList->next = l2;
                l2 = l2->next;
            }

            // Move our new List to the next node
            pNewList = pNewList->next;
        }

        // If the above loop ended
        // We can insert the rest of the list (nodes were already updated in the loop)
        if (l1 == nullptr) 
        {
            pNewList->next = l2;
        }
        else if (l2 == nullptr) 
        {
            pNewList->next = l1;
        }

        return dummy.next;
    }
};
