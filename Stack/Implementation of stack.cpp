#include <iostream>
#include <stack>

using namespace std;


//Method -2
//Implementation of stack using array
class Stack{
    public:

    int* arr;
    int top;
    int size;

    Stack(int s) {
        size = s;
        arr = new int[s];
        top = -1;
    }

    void push(int d) {
        if(top <= size) {
            top++;
            arr[top] = d;
        }
        else{
            cout<<"Stack is Overflow "<<endl;
        }
    }

    void peek() {
        if(top!=-1) {
            cout<<"Peek element of Stack is "<<arr[top]<<endl;
        }
        else{
            cout<<"Stack is Empty "<<endl;
        }
    }

    void pop() {
        if(top!=-1) {
            top--;
            cout<<"Top Element in Stack is : "<<arr[top]<<endl;
        }
        else{
            cout<<"Stack is UnderFlow "<<endl;
        }
    }

};

int main() {


    Stack st(5);
    for(int i=0;i<5;i++) {
        int p;
        cin>>p;
        st.push(p);
    }

    st.peek();
    st.pop();



    //Method - 1
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout<<"Size of Stack is :"<<s.size()<<endl;
    cout<<"Top element of stack is : "<<s.top()<<endl;
    if(s.empty()) {
        cout<<"Stack is Empty"<<endl;
    }
    else{
        cout<<"Stack is nor empty "<<endl;
    }
    s.pop();
    cout<<"After pop, Top element of stack is : "<<s.top()<<endl;



}