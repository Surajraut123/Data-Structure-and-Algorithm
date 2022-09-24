#include <bits/stdc++.h>
using namespace std;

void Intersection(int a[], int n, int b[], int m){
    int p=0;
    int c[100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int k =a[i]^b[j];
            if(k==0){
                c[p] = b[j];
                p++;
            }
        }
    }
    cout<<"Intersection of Array : ";
    for(int i=0;i<p;i++){
        cout<<c[i]<<" ";
    }

}


//Intersection of two sorted array
void intersectionArray(int a[], int b[], int n, int m) {
    vector<int> v(m+n);

    int i=0, j=0;
    while(i<n && j<m) {
        if(a[i] < b[j]) {
            i++;
        }
        else if(a[i] > b[j]) {
            j++;
        }
        else{
            cout<<a[i++] << " ";
            j++;
        }
    }
}

int main(){
    int n,m;
    cout<<"Size of Both Array : ";
    cin>>n>>m;
    int a[n];
    int b[m];
    cout<<"Element in First Array : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Element in Second Array : ";
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    Intersection(a,n,b,m);
}