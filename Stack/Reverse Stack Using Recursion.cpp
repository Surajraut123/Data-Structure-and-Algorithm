#include <iostream>
#include <stack>

using namespace std;


void insertAtBottom(stack<int>& stack, int ele) {
	if(stack.empty()) {
		stack.push(ele);
		return;
	}
	
	int p = stack.top();
	stack.pop();
	insertAtBottom(stack, ele);
	stack.push(p);
}

void reverseStack(stack<int> &stack) {
    if(stack.empty()) {
		return;
	}
	
	int p = stack.top();
	stack.pop();
	reverseStack(stack);
	
	insertAtBottom(stack, p);
		
}
int main() {

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStack(st);
    
    int n = st.size();
    for(int i=0;i<n;i++) {
        cout<<st.top() << endl;
        st.pop();
    }
    
}