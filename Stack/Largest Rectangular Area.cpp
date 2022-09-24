#include <iostream>
#include <stack>
#include<vector>

using namespace std;

vector<int> nextSmaller(vector<int> ans, int n) {
    stack<int> s;
    s.push(-1);

    vector<int> arr(n);
    for(int i=n-1;i>=0;i--) {
        int curr = ans[i];

        while(s.top() != -1 && (ans[s.top()]>=curr)) {
            s.pop();
        }
        arr[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmaller(vector<int> ans, int n) {
    stack<int> s;
    s.push(-1);

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        int curr = ans[i];

        while(s.top() != -1 && (ans[s.top()]>=curr)) {
            s.pop();
        }
        arr[i] = s.top();
        s.push(i);
    }
}

void LargestArea(vector<int> arr, int n) {

    //First we have to find next Smaller and prev smaller indexes

    vector<int> next(n);
    next = nextSmaller(arr, n);

    vector<int> prev(n);
    prev = prevSmaller(arr,n);

    int area = INT16_MIN;
    for(int i=0;i<n;i++) {
        int length = arr[i];

        if(next[i] == -1) {
            next[i] = n;
        }

        int breadth = next[i]-prev[i]-1;
        int newarea= length*breadth;
        area = max(area, newarea);
    }

    cout<<"Area of Rectangle : "<<area<<endl;

}

int main() {

    int n;
    cout<<"Enter Size"<<endl;
    cin>>n;
    vector<int> ans(n);

    for(int i=0;i<n;i++) {
        cin>>ans[i];
    }
    cout<<"Elements are : ";
    for(int i=0;i<n;i++) {
        cout << ans[i];
    }
    cout<<endl;
    LargestArea(ans, n);

}