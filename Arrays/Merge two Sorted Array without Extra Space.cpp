#include <iostream>
#include <algorithm>
using namespace std;

void mergeTwoArray(int a[], int n, int b[], int m){
    int i = n-1;
    int j = 0;
    while(i>=0 && j<m){
        if(a[i] > b[j]){
            swap(a[i], b[j]);
            i--; j++;
        }
        else{
            i--;j++;
        }
    }
    sort(a, a+n);
    sort(b, b+m);
    cout<<"First Array : ";
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Second Array : ";
    for(int i=0;i<m;i++) {
        cout<<b[i]<<" ";
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    int b[m];
    cout<<"First Array : ";
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    cout<<"Second Array : ";
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }
    mergeTwoArray(a, n, b, m);
}