#include <iostream>
#include<queue>

using namespace std;
//T.C = O(1);
//S.C = O(1);

class Queue {
    int * arr;
    int qfront, qrear, size;
    public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        qrear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == qrear) {
            return true;
        }
        else{
            return false;
        }
    }

    //Insert Element from rear
    void enqueue(int data,int n) {
        if(qrear != size) {
            arr[qrear] = data;
            qrear++;
        }
    }

    void print(int n){
        cout<<"Values in an Queue"<<endl;
        while(qfront!=qrear) {
            cout<<arr[qfront]<<" ";
            qfront++;
        }cout<<endl;
    }


    //Delete Element From Front Side
    int dequeue() {
        if(qfront == qrear) {
            return -1;
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == qrear){
                qfront = 0;
                qrear = 0;
            }
            return ans;
        }
    }

    //Front Element
    void front() {
        if(qfront==qrear) {
            cout<<"Queue is Empty"<<endl;
        }
        else{
            cout<<"Front Element "<<arr[qfront]<<endl;
        }
    }
};


int main() {

    queue<int> q;

    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    cout<<"Front of queue " << q.front() <<endl;
    cout<<"Size of Queue " << q.size() <<endl;

    q.push(111);
    q.push(1411);

    cout<<"Size of Queue " << q.size() <<endl;

    if(q.empty()) {
        cout<<"Queue is empty "<<endl;
    }
    else{
        cout<<"Not Empty" <<endl;
    }
    q.pop();

    //Class Implementation
    Queue st;
    if(st.isEmpty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Non Empty" << endl;
    }

    cout<<"How many Value want to enter "<<endl;
    int n;
    cin>>n;

    while(n--) {
        int k;
        cin>>k;
        st.enqueue(k,n);
    }
    st.print(n);

    int p = st.dequeue();
    cout<<"Popped element from queue is "<<p<<endl;

    st.front();

}