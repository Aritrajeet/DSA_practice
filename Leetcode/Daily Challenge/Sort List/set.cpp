//  We use extra space by creating a set to order the elements.(naive)  
ListNode* sortList(ListNode* head) {
        multiset<int> s;
        ListNode *temp = head;
        while(temp){
            s.insert(temp->val);
            temp = temp->next;
        }
        temp = head;
        for(auto it = s.begin(); it != s.end(); it++){
            temp->val = *it;
            temp = temp->next;
        }
        return head;
    }
