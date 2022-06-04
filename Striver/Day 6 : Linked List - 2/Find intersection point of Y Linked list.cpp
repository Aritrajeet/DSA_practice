//Question : https://leetcode.com/problems/intersection-of-two-linked-lists/

//Solution : Method 1 = Use a set to store elements
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set <ListNode*> s;
        while(headA){
            s.insert(headA);
            headA = headA->next;
        }
        while(headB){
            set<ListNode*>::iterator it = s.find(headB);      //find the duplicate
            if (it != s.end()){
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};

//Method 2 (memory efficient) = By observation, first move the longer linked list curr pointer next until distance of curr ptr of both the list should be equidistant from the intersection
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA=0,countB=0;
        ListNode *temp;
        temp = headA;
        while(temp){
            countA++;
            temp = temp->next;      //length of first list
        }
        temp = headB;
        while(temp){
            countB++;
            temp = temp->next;      //length of second list
        }
        ListNode *a = headA;
        ListNode *b = headB;
        if (countA>countB){
            for (int i=0; i<countA-countB;i++){     //make equidistant from intersection
                a = a->next;
            }
        }
        else {
            for (int i=0; i<countB-countA;i++){     //make equidistant from intersection
                b = b->next;
            }
        }
        while(a){
            if (a == b) return a;     //move both ptr one by one. They will surely meet at the intersection pt.
            a = a->next;
            b = b->next;
        }
        
        return a;
    }
};
