#include <iostream>
#include <stack>

using namespace std;

int main() {

    //T.C = O(n);
    //S.C = O(n);
    string s = "Suraj";
    stack<char> st;
    for(int i=0; i<s.length(); i++) {
        st.push(s.at(i));
    }

    string ans = "";
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    cout<<"Reverse String : "<<ans<<endl;

}