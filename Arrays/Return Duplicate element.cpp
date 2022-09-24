#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    // Time Complexity - > O(n*n);
    // Space Complexity - > O(1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]==nums[j]){
                cout<< nums[i];
            }
        }
    }

    //Time Complexity ->   O(n);
    //Space Complexity -> O(n);
    unordered_set <int> s;
    s.insert(nums[0]);
    for(int i=1;i<n;i++){
        if(s.count(nums[i])){
            cout<< nums[i];
        }
        else{
            s.insert(nums[i]);
        }
    }

    //Time Complexity ->   O(n);
    //Space Complexity -> O(1);
    int slow = nums[0];
    int fast = nums[0];
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow!=fast);

    fast = nums[0];
    while(slow!=fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    cout<<slow;


    //Time Complexity : O(n)
    //Space Complexity : O(n)
    int result[n]; 
    for(int i=0;i<n;i++){
        result[i] = 0;
    }
    for(int i=0;i<n;i++){
        result[nums[i]-1]++;
    }
    for(int i =0;i<n;i++){
        if(result[i] > 1){
            cout<<"Duplicate Element is : "<<i+1;
        }
    }
    


    return 0;

}   