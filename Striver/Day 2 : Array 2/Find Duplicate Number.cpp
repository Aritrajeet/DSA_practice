//Question:

//Solution:Method 1 (Brute) : Sort and duplicate will be consecutive       -O(nlogn)
//Method 2: Map method - extra space but efficient
//Method 3: Floyd slow fast method (Linked list)    - efficient and in place
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0],fast = nums[0];
        do {
            slow = nums[slow];    //slow = slow->next
            fast = nums[nums[fast]];    //fast = fast->next->next
        }
        while(slow != fast);    //when slow and fast meet the cycle in detected i.e. duplicate is there
        
        slow = nums[0]; 
        while(slow != fast){      //now move both slow and fast ptr one step until they meet. Here, they will reach at the duplicate number together
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
