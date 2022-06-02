//Question: https://leetcode.com/problems/reverse-linked-list/

//Solution: 1->2->3 : prev = NULL , curr = 1 , temp = 2 < curr->next = temp >
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head , *temp = head;
        if (!curr or !curr->next) return head;

        while(curr != NULL){
            temp = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
