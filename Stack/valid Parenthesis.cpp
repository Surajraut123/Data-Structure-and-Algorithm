#include <iostream>
#include <stack>

using namespace std;

bool valid(string s) {
    
    stack<int> st;
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];

        if(ch=='(' || ch=='[' || ch=='{') {
            st.push(ch);
        }
        else{

            if(!st.empty()) {
                int peek = st.top();
                if((peek=='(' && ch==')') || (peek=='{' && ch=='}') || (peek=='[' && ch==']')) {
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(st.empty()) {
        return true;
    }
    else{
        return false;
    }

}

int main() {

    string s;
    cout<<"Enter the String of Paarenthesis : "<<endl;
    cin>>s;
    if(valid(s)) {
        cout << "It is a valid Parenthesis " << endl;
    }
    else{
        cout << "It is not a valid Parenthesis " << endl;
    }
}