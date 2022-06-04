//Question: https://leetcode.com/problems/linked-list-cycle-ii/

//Solution: Flyod slow fast pointer
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(!head) return head;
        bool flag = false;
        while(slow and fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                flag = true;
                break;
            }
        }
        if(!flag) return NULL;
        slow = head;
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
