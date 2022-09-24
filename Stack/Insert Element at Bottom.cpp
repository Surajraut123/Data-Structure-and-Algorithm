#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int>& s, int ele) {
    if(s.empty()) {
        s.push(ele);
        return;
    }
    int t = s.top();
    s.pop();
    insertAtBottom(s, ele);
    s.push(t);
}

int main() {

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    int e;
    cout<<"Enter Element to insert at Bottom of Stack "<<endl;
    cin>>e;

    insertAtBottom(st, e);
    int n = st.size();
    for(int i=0;i<n;i++) {
        cout<<st.top() << endl;
        st.pop();
    }
    
}