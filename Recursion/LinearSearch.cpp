#include<iostream>
using namespace std;

bool search(int *arr, int n, int key) {
    if(arr[0] == key) {
        return true;
    }
    
    else{
        search(arr+1,n-1,key);
    }

    return false;

}

    

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];

    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"Enter the Element to Search" << endl;
    int key;
    cin>>key;

    if(search(arr,n,key)) {
        cout<<"Element is Found "<<endl;
    }
    else{
        cout<<"Element is not Found"<<endl;
    }
}