#include <iostream>
#include <stack>

using namespace std;

bool redundant(string s, stack<char>& st) {

    //we are not considering character here
    
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/' ) {
            st.push(ch);
        }
        else{
            if(ch==')') {
                bool isRedundant = true;
                while(st.top() != '(') {
                    if(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/' ){
                        isRedundant = false;
                    }
                    st.top();
                }

                if(isRedundant) {
                    return true;
                }
            }

        }
    }
    return false;
}

int main() {

    string s = "((a+b))";
    stack<char> st;
    if(redundant(s, st)){
        cout<<"It is Not redundant"<<endl;
    }
    else{
        cout<<"It is redundant"<<endl;
    }
}