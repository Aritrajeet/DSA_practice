//Question: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

//Solution: 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode*curr = head;
        while(curr != NULL){
            curr = curr->next;
            length++;     //get the length of the linked list
        }
        curr = head;
        if (length == n){
            return head->next;      //delete first node from start
        }
        for(int i=1; i< length-n; i++){
            curr=curr->next;      //nth node from end is (length-n)th node from start
        }
        if (curr->next == NULL)     //no deletion
            return head;
        if (curr->next->next == NULL){
            curr->next = NULL;  //delete last node
            return head;
        }
        curr->next = curr->next->next;      //delete nth node
        
        return head;
    }
};
