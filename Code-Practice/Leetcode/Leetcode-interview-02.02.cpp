/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    int kthToLast(ListNode* head, int k) 
    {
        ListNode* pa  = head;
        ListNode* pb  = head;

        while(k > 1)
        {
            pa = pa->next;
            k--;
        }

        while(pa->next != NULL)
        {
            pa = pa->next;
            pb = pb->next;
        }

        return pb->val;
    }
};