//Question: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#

//Solution: Idea is to take a pair of linked list(from the end) and merge them. Do this recursively to get the single merged list.

Node *merge(Node *root1, Node *root2){      //simple merge 2 sorted linked list algo
    Node *curr1 = root1, *curr2 = root2;
    Node *head = new Node(-1);      //dummy node
    Node *temp = head;
    while(curr1 and curr2){
        if (curr1->data < curr2->data){
            temp->bottom = curr1;
            temp = temp->bottom;
            curr1 = curr1->bottom;
        }
        else{
            temp->bottom = curr2;
            temp = temp->bottom;
            curr2 = curr2->bottom;
        }
    }
    if(curr1) temp->bottom = curr1;
    if(curr2) temp->bottom = curr2;
    return head->bottom;
}
Node *flatten(Node *root)
{
   if(!root or !root->next) return root;
   
   root->next = flatten(root->next);      //move right
   root = merge(root,root->next);       //merge two lists at a time
   return root;
}
