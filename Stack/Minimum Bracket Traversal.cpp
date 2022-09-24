#include <iostream>
#include <stack>

using namespace std;


int cost(string s) {
    stack<int> st;
    //For Odd length size we can't do the valid string
    if(s.length()%2 == 1) {
        return -1;
    }
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        if(ch == '{') {
            st.push(ch);
        }
        else{
            if(st.empty() && st.top() == '{') {
                st.pop();
            }
            st.push(ch);
        }
    }

    int a=0, b=0;
    for(int i=0;i<s.length(); i++) {
        if(s[i] == '{') {
            a++;
        }
        else{
            b++;
        }
    }
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}

int main() {

    /*
    “{}{}”, “{{}}”, “{{}{}}” are valid strings while “}{}”, “{}}{{}”, “{{}}}{“ are not valid strings.

    And if they are invalid we have to do in a valid stage with minimum cost and return that perticular cost
    */

    string s = "{}{}";
    int a = cost(s);
    cout<<"Minimum cost of valid string "<<a<<endl;

    

}