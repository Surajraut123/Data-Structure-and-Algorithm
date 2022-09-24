#include <iostream>
#include <stack>

using namespace std;

void sortS(stack<int>& s, int ele) {
    if(s.empty() || s.top() < ele) {
        s.push(ele);
        return;
    }

    int i = s.top();
    s.pop();
    sortS(s, ele);
    s.push(i);

}

void sortStack(stack<int>& s) {
    if(s.empty()) {
        return;
    }

    //Taking each element Outside
    int e = s.top();
    s.pop();
    sortStack(s);

    //and checking condition for sort for each element

    sortS(s, e);


}
int main() {

    stack<int> st;
    st.push(18);
    st.push(1);
    st.push(2);
    st.push(45);
    st.push(5);
    sortStack(st);
    
    int n = st.size();
    for(int i=0;i<n;i++) {
        cout<<st.top() << endl;
        st.pop();
    }
    
}