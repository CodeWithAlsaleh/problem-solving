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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
         return NULL;

        if(!head->next)
        {
            if(head->val == val)
             return NULL;
            else
             return head;
        }

        // Also u can add dummy node at the beginning in order to make it simple
        ListNode* cur = head->next , *prev = head;

        while(cur)
        {
            while(cur and cur->val == val)
            {
                cur = cur->next;
                prev->next = cur;
            }
            
            prev = cur;
            if(cur)
                cur = cur->next;
        }

        if(head->val == val)
            return head->next;
        else
            return head;
    }
};
