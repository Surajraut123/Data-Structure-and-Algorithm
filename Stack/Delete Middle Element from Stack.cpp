#include <iostream>
#include <stack>

using namespace std;

 void solve(stack<int>&s, int count, int n) {
        if(count==n/2) {
            s.pop();
            return;
        }
        
        int a = s.top();
        s.pop();
        
        solve(s, count+1, n);
        s.push(a);
    }

void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int count=0;
        solve(s, count, sizeOfStack);
    }
int main() {

    //Method - 1
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    int n = s.size();
    deleteMid(s, s.size());

    for(int i=0;i<n; i++) {
        cout<<s.top()<<endl;
        s.pop();
    }

    


}