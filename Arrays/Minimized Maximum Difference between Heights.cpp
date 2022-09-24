

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"K element :";
    int k;
    cin>>k;
    sort(arr, arr+n);
    int ans = arr[n-1] - arr[0];
    int ma, mi;
    for(int i=1;i<n;i++){
        if(arr[i]>=k){
            ma = max(arr[i-1]+k, arr[n-1]-k);
            mi = min(arr[0]+k, arr[i]+k);
            ans = min(ans, ma-mi);
        }
    }
    cout<<"Minimized the maximum difference : "<<ans<<endl;
    return 0;

    return 0;
}
