class Solution {
    public ListNode swapPairs(ListNode head) {
        
        ListNode temp = head;
        boolean flag = false;
        
        while(temp != null && temp.next != null)
        {
           
            if(flag == false)                        // Handling for first two elements separately and setting heade pointer.
            {
                ListNode temp1 = temp;
                ListNode temp2 = temp1.next;
                 
                temp1.next = temp2.next;               // Logic for swapping the nodes of linked list.
                temp2.next = temp1;
                head = temp2;
                temp = temp1;
                flag = true;
            }
          
          
            else                                  // Handling rest of the cases .
            {
             ListNode temp1 = temp.next;
             ListNode temp2 = temp1.next;
                 
             if(temp2 == null)                      // this condition will execute if there is odd no of elements in  linked list.
                 break;
            
             temp1.next = temp2.next;             // Logic for swapping the nodes of linked list.
             temp2.next = temp1;
             temp.next = temp2;
             temp = temp1;
            }
            
        }
        
        return head;
    }
}
