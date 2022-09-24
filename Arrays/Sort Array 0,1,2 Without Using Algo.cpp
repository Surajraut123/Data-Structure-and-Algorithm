#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Size : ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int zero = 0;
    int one = 0;
    int two = 0;
    for(int i=0;i<n;i++){
        switch(arr[i]){
            case 0: zero++;break;
            case 1: one++;break;
            case 2: two++;break;
        }
    }
    int i=0;
    while(zero>0){
        arr[i++] = 0;
        zero--;
    }
    while(one>0){
        arr[i++] = 1;
        one--;
    }
    while(two>0){
        arr[i++] = 2;
        two--;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    

    
}