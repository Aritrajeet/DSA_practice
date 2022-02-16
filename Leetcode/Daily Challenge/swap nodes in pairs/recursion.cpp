    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *temp = swapPairs(second->next);
        second->next = first;
        first->next = temp;
        return second;
    }
