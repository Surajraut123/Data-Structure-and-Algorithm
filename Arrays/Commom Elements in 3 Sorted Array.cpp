
#include<bits/stdc++.h>
using namespace std;

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            unordered_map<int, int> mp1, mp2, mp3;
            for(int i=0;i<n1;i++) mp1[A[i]]++;
            for(int i=0;i<n2;i++) mp2[B[i]]++;
            for(int i=0;i<n3;i++) mp3[C[i]]++;
            vector<int> ans;
            for(int i=0;i<n1;i++) {
                if(mp1[A[i]] && mp2[A[i]] && mp3[A[i]]) {
                    ans.push_back(A[i]);
                    mp1[A[i]]=0;
                }
            }
            
            return ans;
        }

int main() {
    int n;
    cout<<"Size: 1 Array ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int n1;
    cout<<"Size: 2 Array ";
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    int n2;
    cout<<"Size: 3 Array";
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }

    vector<int> ans = commonElements(arr, arr1, arr2, n, n1, n2);
    cout<<"Common Elements :"<<endl;
    for(int i=0;i<n2;i++){
        cout<<ans[i] << " ";
    }

    return 0;
}