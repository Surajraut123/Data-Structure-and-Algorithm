#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }
};

void implementCircular(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* tmp = new Node(data);
        head = tmp;
        tail = tmp;
        head -> next = head;
    }

    else{
        Node* curr=head;
        while(curr->next != head) {
            curr = curr ->next;
        }

        Node* tmp= new Node(data);
        tmp -> next = curr ->next;
        curr -> next = tmp;
        tail = tmp;
    }


}

void traverseList(Node* head) {
    // if(head -> next = head){
        
    //     cout<<head->data<<" ";
    // }    
    Node* tmp = head;
    do{
        cout<<head -> data<<" ";
        head = head ->next;
    }while(head != tmp);
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int k;
    cout<<"How many nodes want to put : "<<endl;
    cin>>k;
    while(k>0) 
    {
        int data;
        cout<<"Enter the data : "<<endl;
        cin>> data;
        implementCircular(head, tail, data);
       
        traverseList(head);
        cout<<endl;
        k--;
        if(k==0) {
            cout<<"Do you want to Enter More Nodes Press : 0 "<<endl;
            cout<<"How many nodes want to put : IF NOT ENTER 0"<<endl;
            int p;
            cin>>p;
            k = k+ p;
        }
    }
    

}