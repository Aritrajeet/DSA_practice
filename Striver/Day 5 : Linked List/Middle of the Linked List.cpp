//Question: https://leetcode.com/problems/middle-of-the-linked-list/

//Solution: 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL and fast->next != NULL){     //when fast pointer reaches end slow is in the middle
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
