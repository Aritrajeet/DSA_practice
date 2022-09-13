// https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1

    sort(arr,arr+ size);
    int left=0,right = 1;   // we dont take right as the end ptr because there is no meaning when arr[right] - arr[left] < n or >n in that case: whichever ptr you move it will give same result.
    while(left< size and right < size){
        if(left == right){
            right++;  // dont take same element
        }
        if(arr[right] - arr[left] == n){
            return true;
        }
        if(arr[right] - arr[left] < n){
            right++;
        }
        else left++;
    }
    return false;
