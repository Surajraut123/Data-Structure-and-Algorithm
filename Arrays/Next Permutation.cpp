

#include <bits/stdc++.h>

using namespace std;


void nextPermutation(int nums[], int n){
    int idx = -1;
    for(int i=n-1;i>0;i--){
        if(nums[i]>nums[i-1]){
            idx = i;
            break;
        }
    }
    if(idx ==-1){
        reverse(nums, nums+n);
    }
    else{
        int prev = idx;
        for(int i=idx+1;i<n;i++){
            if((nums[i] > nums[idx-1]) && nums[i] <= nums[prev]){
                prev = i;
            }
        }
         swap(nums[prev], nums[idx-1]);
         reverse(nums+idx, nums+n);
    } 
    cout<<"Next Permutation : ";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    nextPermutation(arr,n);

    return 0;
}
