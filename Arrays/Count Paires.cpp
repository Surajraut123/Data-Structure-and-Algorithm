#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;



int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        int lo=0;
        int hi=n-1;
       while(lo<hi){
            if(nums[lo]+nums[hi]==k)
            {  count++;
             lo++;
             hi--;}
           else if(nums[lo]+nums[hi]<k)
           { lo++;}
             else
                 hi--;
        }
        return count;
    }

int main() {
    vector<int> ans;
    int n;
    cout<<"Enter the Total Length of Vector : "<<endl;
    cin>>n;
    int data;
    for(int i=0;i<n;i++) {
      cin>> data;
      ans.push_back(data);
    }
    cout<<"Enter the Sum  : "<<endl;
    int k ;
    cin>>k;
    int p = maxOperations(ans, k);
}