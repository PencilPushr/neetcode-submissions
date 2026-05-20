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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummy = new ListNode(0);
        ListNode* start = dummy;

        int carry = 0;
        while(l1 != nullptr | l2 != nullptr | carry != 0)
        {
            int a = (l1 == nullptr) ? 0 : l1->val;
            int b = (l2 == nullptr) ? 0 : l2->val;

            int value = a + b + carry;
            carry = value / 10;
            value = value % 10;
            start->next = new ListNode(value);

            //iterate 
            start = start->next;
            l1 = (l1 == nullptr) ? nullptr : l1->next;
            l2 = (l2 == nullptr) ? nullptr : l2->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;

    }
};
