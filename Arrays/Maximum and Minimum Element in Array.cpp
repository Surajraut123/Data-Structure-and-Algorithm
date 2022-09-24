#include <iostream>
#include <utility>
using namespace std;
void maximum(int arr[], int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    cout<<"Maximum Element : "<<max;
}
void minimum(int arr[], int n){
    int min = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    cout<<"Minimum Element : "<<min;
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
    maximum(arr,n);
    minimum(arr,n);
    
}