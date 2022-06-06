//Question: https://leetcode.com/problems/rotate-list/

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
class Solution {      //Method 1 : do operation k times
public:
    ListNode* rotateRight(ListNode* head, int k) {
                
        ListNode *curr = head;
        if(!curr or !curr->next) return curr;
        int len = 0;
        while(curr){
            curr = curr->next;
            len++;
        }
        k = k % len;
        curr = head;
        while(k--){     //move last node to first n times
            curr = head; 
            while(curr->next and curr->next->next){
                curr = curr->next;
            }
            ListNode *temp;
            temp = curr->next;
            curr->next = NULL;
            temp->next = head;
            head = temp;
            
        }
        return head;
    }
};

//Method 2: directly get the final result
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;             
        ListNode* temp = head;
        int len = 1;
        while(temp->next != NULL){               
            len++;
            temp = temp->next;
        } 
        if(k >= len) k = k % len;                
        temp->next = head;
        k = len - k;      //we will move len - k steps . Then the next node is the new Head . So, break the list here.
        while(k--){                             
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
