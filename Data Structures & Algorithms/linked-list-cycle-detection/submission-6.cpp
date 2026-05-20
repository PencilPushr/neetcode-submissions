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

    bool hasCycle(ListNode* head) 
    {
        if (!head) return false;

        ListNode* pSlow = head;
        ListNode* pFast = head->next;

        // We have reached the end of the list
            // Therefore return false
        while( pFast && pFast->next )
        {
            // Terminal condition
            if ( pSlow == pFast ) 
                return true;

            // Move around the list
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        } 

        return false;
    }
};
