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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* pPrev = nullptr;
        ListNode* pCur = head;
        while(pCur != nullptr)
        {
            ListNode* temp = pCur->next;
            pCur->next = pPrev;
            pPrev = pCur;
            pCur = temp;
            //head = pCur;
        }
     
        return pPrev;
    }
};
