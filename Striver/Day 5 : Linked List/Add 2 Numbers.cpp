//Question: https://leetcode.com/problems/add-two-numbers/

//Solution:
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode (0);      //dummy head for new linked list
        ListNode *curr1 = l1, *curr2 = l2, *temp = head;
        int carry = 0;
        while(curr1 or curr2){
            int val1=0,val2=0;
            if (curr1){
                val1 = curr1->val;
            }
            if (curr2){
                val2 = curr2->val;
            }
            temp->next = new ListNode((val1+val2+carry) % 10);      //here we create a node and assign the sum of 2 digits
            temp = temp->next;
            carry = (val1+val2+carry)/10;
            if (curr1) 
                curr1 = curr1->next;
            if (curr2) 
                curr2 = curr2->next;
        }
        if (carry)
            temp->next = new ListNode(carry);     //if carry is left we add a new digit
        return head->next;      //head is dummy , but next node is our first digit
    }
    
};
