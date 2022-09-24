#include<iostream>
using namespace std;

bool search(int *arr, int n, int s, int e, int key) {
    if(s>e) {
        return false;
    }
    int mid = (s+e)/2;
    if(arr[mid] == key) {
        return true;
    }
    if(arr[mid] < key) {
        return search(arr, n, mid+1, e, key);
    }
    else{
         return search(arr, n, s, mid-1, key);
    }
    

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

    if(search(arr,n,0,n-1,key)) {
        cout<<"Element is Found "<<endl;
    }
    else{
        cout<<"Element is not Found"<<endl;
    }
}