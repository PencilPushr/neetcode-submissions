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
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int value1 = (l1 != nullptr) ? l1->val : 0;
            int value2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate new value
            int current_value = value1 + value2 + carry;

            carry = current_value / 10; // This removes the digit and leaves the tens
            current_value = current_value % 10; // pops the current value

            cur->next = new ListNode(current_value);

            // Iterate 
            cur = cur->next;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        // Handle edge case we got to the end of the list but we still have stuff in carry.
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
