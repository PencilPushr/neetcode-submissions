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
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        ListNode dummy(-1);
        ListNode* result = &dummy;

        while(l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                result->next = l1;
                l1 = l1->next;
            }
            else
            {
                result->next = l2;
                l2 = l2->next;
            }
            result = result->next;
        }

        result->next = (l1 != nullptr) ? l1 : l2;

        return dummy.next;        
    }
};
