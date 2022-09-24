#include <iostream>
#include <utility>
using namespace std;

int *reverse(int arr[], int n){
    int i=0;
    int j=n-1;
    while(i<j){
        swap(arr[i++], arr[j--]);
    }
    return arr;
}
int main(){
    int n;
    cout<<"Enter the Size of Array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elemnt in array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Reverse array :";
    int *p=reverse(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}