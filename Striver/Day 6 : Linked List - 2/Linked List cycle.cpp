//Question: https://leetcode.com/problems/linked-list-cycle/

//Solution : Mehtod 1 (Naive): Maintain a set of pointers. Whenever we move forward we check in the set whether it is present, if yes cycle exists.

//Method 2 : Flyod slow fast algo
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(!head) return false;
        while(slow and fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
