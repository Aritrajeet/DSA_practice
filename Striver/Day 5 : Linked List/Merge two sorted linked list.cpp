//Question: 

//Solution: 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

        if(NULL == l1) return l2;
        if(NULL == l2) return l1;

        ListNode* head=NULL;    // head of the list to return

        // find first element 
        if(l1->val < l2->val) {
          head = l1;
          l1 = l1->next;
        }
        else {
          head = l2;
          l2 = l2->next;
        }

        ListNode* p = head;     // pointer to form new list

        while(l1 && l2){
            if(l1->val < l2->val)   { 
              p->next = l1; 
              l1 = l1->next;
            }
            else  {
              p->next = l2; 
              l2 = l2->next;
            }
            p=p->next;
        }

        if(l1)  p->next=l1;     //l1 is left
        else    p->next=l2;     //l2 is left

        return head;
    }
};
