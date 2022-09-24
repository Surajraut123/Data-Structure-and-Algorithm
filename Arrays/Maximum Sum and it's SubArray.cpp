#include <iostream>
using namespace std;

void MaximumSum(int a[], int n){
    int cur = 0;
    int maxSum = 0;
    for(int i=0;i<n;i++){
        cur = cur + a[i];
        if(maxSum < cur){
            maxSum = cur;
        }
        if(cur < 0){
            cur = 0;
        }
    }

    cout<<"Maximum Sum of Array : "<<maxSum<<endl;
}
void MaximumSumSubArray(int a[], int n){
    int cur = 0;
    int maxSum = 0;
    int start = 0;
    int s = 0;
    int end = 0;
    for(int i=0;i<n;i++){
        cur = cur + a[i];
        if(maxSum < cur){
            maxSum = cur;
            start = s;
            end = i;
        }
        if(cur < 0){
            cur = 0;
            s = i + 1;
        }
    }

    cout<<"Maximum Sum of Sub Array : ";
    for(int i=start; i <= end; i++){
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n,m;
    cout<<"Size of Both Array : ";
    cin>>n;
    int a[n];
    cout<<"Element in First Array : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    

    MaximumSum(a, n);
    MaximumSumSubArray(a, n);
}