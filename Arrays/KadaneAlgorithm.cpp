#include <iostream>
using namespace std;

void MaximumSum(int a[], int n){
    int cur = 0;
    int maxSum = a[0];
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
}