class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        int left = 0;
        int right = people.size()-1;
        sort(people.begin(),people.end());      //sort the arr
        while(left <= right){
            if(people[left] + people[right] <= limit){      //2 pointer method
                count++;
                left++;
                right--;
            }
            else{
                count++;
                right--;
            }
        }
        return count;
    }
};
