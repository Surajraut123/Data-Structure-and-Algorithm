#include <iostream>
#include<vector>
#include<stack>

using namespace std;

void nextSmallerElement(vector<int> arr, int n) {
    stack<int> s;

    //We traversing through end of vector So we know at last element nothing to small.
    //That's why we initially inserted -1 in a stack
    s.push(-1);

    vector<int> ans(n);

    for(int i=n-1; i>=0; i--) {
        int curr = arr[i];

        //Here we finding next Smaller element from curr element
        //We traversing while curr element i.e vector element is greater than top os stack.

        //            initially curr
          
        //EX.2  1  4   3
        //   |  |  |   |
        //   1 -1  3  -1   Required Final Output

        /*

        Here we have to find an Element, who's value is less than curr value.
        -1>=3  F so top of stack putting in ans array and putting current element in stack
        3>=4   F same.
        4>=1   T  then pop while 

        
        
        */

        while(s.top() >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    cout<<"Next Smaller Elements are : ";
    for(int i=0;i<n;i++) {
        cout << ans[i]<<" ";
    }
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
    nextSmallerElement(ans, n);


}