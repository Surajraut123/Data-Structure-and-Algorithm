#include <iostream>
using namespace std;

void withOutSpace(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            if(i!=j){
                swap(arr[i],arr[j]);
            }  
            j++;  
        }
    }
    cout<<"Without Space : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void withSpace(int arr[], int n){
    int p=0;
    int a[n];
	for(int i=0;i<n;i++){
	    if(arr[i]<0){
	        a[p] = arr[i];
	        p++;
	    }
	}
	for(int i=0;i<n;i++){
	    if((arr[i]>0) && (p<n)){
	        a[p] = arr[i];
	        p++;
	    }
	}
    cout<<"With Space : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void shifttall(int arr[], int n){
    int left = 0;
    int right = n-1;
    while(left<=right){
        if(arr[left]<0 && arr[right]<0){
            left++;
        }
        else if(arr[left]>0 && arr[right]<0){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        else if(arr[left]>0 && arr[right]>0){
            left++;
            right--;
        }
        else{
            left++;
            right--;
        }
    }
    cout<<"Shift Tall : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//Without Space and O(n) time Complexity

//Moving all Zero to end
void shiftzeros(int arr[], int n)  {
    int j=0;
    for(int i=0;i<n;i++) {
        if(arr[i] !=0 && arr[j] == 0) {
            if(i!=j) {
                swap(arr[i], arr[j]);
                j++;
            }
        }

        if(arr[j] != 0) {
            j++;
        }
    }

    cout<<"Shifting Zeros at End : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    withSpace(arr,n);

    //Both Are Shifting Larger element at last.
    withOutSpace(arr,n);
    shifttall(arr, n);

    shiftzeros(arr, n);
}
