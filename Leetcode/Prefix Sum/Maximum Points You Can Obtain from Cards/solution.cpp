class Solution {
public:
    int maxScore(vector<int> cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;

        if(n==k)
        {
            return accumulate(cardPoints.begin(),cardPoints.end(),0);           //sum of all elements
        }


        int leftSum = 0;
        int rightSum = 0;

        for(int i=0;i<k;i++)
        {
            leftSum += cardPoints[i];   //left window
        }

        for(int i=n-1;i>=n-k;i--)
        {
            rightSum += cardPoints[i];  //right window
        }

        int left = 0, right = n-1;
        while(k)
        {
            if(leftSum>=rightSum)
            {
                sum += cardPoints[left];
                leftSum -= cardPoints[left];
                left++;
                rightSum -= cardPoints[right-k+1];  //when you take an element from left, the window size in the right decreases by one 
            }
            else
            {
                sum += cardPoints[right];
                rightSum -= cardPoints[right];
                right--;
                leftSum -= cardPoints[left+k-1];    //when you take an element from right, the window size in the left decreases by one 
            }
            k--;
        }
        return sum;
    }
};
