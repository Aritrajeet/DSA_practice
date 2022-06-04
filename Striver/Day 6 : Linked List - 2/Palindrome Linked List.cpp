//Question: https://leetcode.com/problems/palindrome-linked-list/

//Solution: We maintain a stack and we fill it till the middle . Then after that we pop it. If at any point stack top element is not eq to linked list node means not a palindrome
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return NULL;
        stack<int> s;
        int len = 0;
        ListNode *temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        temp = head;
        int i=0;
        while(i < len/2){
            s.push(temp->val);
            temp = temp->next;
            i++;
        }
        if(len%2 != 0){
            temp = temp->next;
        }
        while(temp){
            if (temp->val != s.top()){
                return false;
            }
            s.pop();
            temp = temp->next;
        }
        return true;
    }
};

//There is another memory efficient method. Palindrome linked list will be same when reversed. So we can reverse the linked list and check till middle. If all elements are same means it is a palindrome.
