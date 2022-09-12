//https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

int majorityElement(int a[], int size)
    {
  //first we find the most frequent element then check whether the frequency of this element is more than n/2
        int idx = 0,count = 1;
        for (int i=1; i<size; i++){
            if(a[idx] == a[i]){
                count++;        //increase the frequency of probable majority element
            }
            else{
                count--;    // decrease if not the probable majority element
            }
            if(count == 0){   //the curr element can become the majority element
                idx = i;
                count = 1;
            }
        }
        count = 0;
        int probable_ans = idx;     //since this was the most occuring element, it has chances of becoming the majority element.
        for (int i=0; i<size; i++){
            if(a[i] == a[probable_ans]){
                count++;    //count the frequency of most freq element
            }
        }
        if(count <= size/2){
            return -1;    // majority element does not exists
        }
        return a[probable_ans];   
    }
