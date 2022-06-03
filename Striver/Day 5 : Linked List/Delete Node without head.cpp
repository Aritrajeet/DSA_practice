//Question: https://leetcode.com/problems/delete-node-in-a-linked-list/

//Solution: idea is to put all elements one by one to its left node then delete the last node
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * prev = node;
        ListNode * curr = prev->next;
        while(curr and curr->next){
            prev->val = curr->val;
            prev = curr;
            curr = curr->next;
        }
        prev->val = curr->val;
        prev->next = NULL;
    }
};
