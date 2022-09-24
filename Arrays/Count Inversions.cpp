#include <iostream>
using namespace std;


long long mergesort(long long arr[],long long temp[],long long int left,long long int right)
    {
        long long int mid,invC=0;
        if(left<right)
        {
            mid=(left+right)/2;
            invC+=mergesort(arr,temp,left,mid);
            invC+=mergesort(arr,temp,mid+1,right);
            
            invC+=merge(arr,temp,left,mid+1,right);
        }
        
        return invC;
    }
    
    long long int merge(long long arr[],long long temp[],long long int left,long long int mid,long long int right)
    {
        long long int i,j,k;
        long long int invC=0;
        i=left;
        j=mid;
        k=left;
        
        while((i<=mid-1) && (j<=right))
        {
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }
            else
            {
                temp[k++]=arr[j++];
                invC+=mid-i;
            }
        }
        
        while(i<=mid-1)
        {
            temp[k++]=arr[i++];
        }
        while(j<=right)
        {
            temp[k++]=arr[j++];
        }
        
        for(int i=left;i<=right;i++)
        {
            arr[i]=temp[i];
        }
        
        return invC;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        long long int inversionC =  mergesort(arr,temp,0,N-1);
        return inversionC;
    }

int main() {
    int n;
    cout<<"Size : ";
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    inversionCount(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}