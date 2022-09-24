#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the Number : "<<endl;
    cin>>n;

    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    long long  maxProduct = 0;
    long long currProduct = 0;
    
    for(int i=0;i<n;i++) {
        currProduct = currProduct * arr[i];
        if(currProduct > maxProduct) {
            maxProduct = currProduct;
        }
    }
    cout<<endl;
    cout<<"Max Product : " <<maxProduct;
    return 0;
}