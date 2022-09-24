#include<iostream>
using namespace std;

int sumArray(int *arr, int n) {
    if(n==0) {
        return 0;
    }

    if(n==1) {
        return arr[0];
    }

    int remainPart = sumArray(arr+1,n-1);
    int sum = arr[0] + remainPart;
    return sum;
}

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];

    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    int sum = sumArray(arr, n);
    cout<<sum;

    
}