#include <bits/stdc++.h>
using namespace std;


// This is for unsorted array
void UnionOfArray(int a[], int n, int b[], int m){
    unordered_set<int> set;
    for(int i=0;i<n;i++){
        set.insert(a[i]);
    }
    for(int i=0;i<m;i++){
        set.insert(b[i]);
    }
    cout<<"Total Number of Union Element : "<<set.size()<<endl;
}


// For Sorted Array, But This will not work for Duplicates Elements in an one array

void UnionofSortedArray(int a[], int b[], int n, int m) {
    vector<int> ans;

    int i=0;
    int j=0;

    while(i < n && j < m) {
        if(a[i] < b[j]) {
            ans.push_back(a[i++]);
        }
        else if(a[i] > b[j]) {
            ans.push_back(b[j++]);
        }
        else{
            ans.push_back(a[i++]);
            j++;
        }
    }

    while(i<n) {
        ans.push_back(a[i++]);
    }
    while(j<m) {
        ans.push_back(b[j++]);
    }
    int k = ans.size();
    for(int i=0;i<k;i++){
        cout<<ans[k] <<" ";
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
    UnionOfArray(a,n,b,m);
}