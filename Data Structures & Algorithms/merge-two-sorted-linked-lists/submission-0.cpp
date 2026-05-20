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
        ListNode dummy(0);
        ListNode* newList = &dummy;
        auto l1 = list1;
        auto l2 = list2;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                newList->next = l1;
                l1 = l1->next;
            }
            else
            {
                newList->next = l2;
                l2 = l2->next;
            }
            newList = newList->next;
        } 

        if (l1)
        {
            newList->next = l1;
        }
        else
        {
            newList->next = l2;
        }

        return dummy.next;
    }
};
