#include <iostream>
using namespace std;
class Node {
    public :
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int value = this-> data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is Free Now ";
    }
};

void InsertAtLast(Node* &head, int d){
    Node* tmp = head;
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }
    Node * tmp1 = new Node(d);
    tmp->next = tmp1;
    tmp1 -> next = NULL;
    
}
void InsertAtBegin(Node* &head, int d){
    Node * tmp = new Node(d);
    tmp -> next = head;
    head  = tmp;
}
void insertAtPosition(Node* &head, int position, int d){
    if(position==1){
        InsertAtBegin(head, d);
        return;
    }
    Node* tmp = head;
    int cnt=1;
    while(cnt < position-1){
        tmp = tmp->next;
        cnt++;
    }
    Node* inser = new Node(d);
    inser -> next = tmp -> next;
    tmp -> next = inser;
}

void traverse(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}

void sort012(Node* head) {
    Node* curr = head;
    int zero =0;
    int one =0;
    int two =0;
    while(curr!=NULL) {
        int value = curr -> data;
        if(value == 0) {
            zero++;
        }
        else if(value == 1) {
            one++;
        }
        else{
            two++;
        }
        curr = curr -> next;
    }
    curr = head;
    while(curr !=NULL) {
        if(zero>0) {
            curr -> data = 0;
            zero--;
        }
        else if(one>0) {
            curr -> data = 1;
            one--;
        }
        else if(two>0){
            curr -> data = 2;
            two--;
        }
        curr = curr -> next;
    }
    cout<<"Sorted List of 0s, 1s 2s : "<<endl;
    traverse(head);

}


//if Questions is like : Data or Node Replacement is not allowed
//Then We have links to replace and connect to nodes;

void insertAtTail(Node* &tail, Node* curr) {
    tail-> next = curr;
    tail = curr;
}

void DataReplacementNotAllowed(Node* head) {
    
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    while(curr != NULL) {
        int value = curr -> data;

        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }

        else{
            insertAtTail(twoTail, curr);
        }
        curr = curr -> next;
    }

    //For this is One list is empty then we can directly connect to the second list
    // zeroTail -> next = oneHead -> next;
    
    if(oneTail != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else{
        zeroTail -> next = twoHead -> next;
    }
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    //update heaad;
    head = zeroHead ->next;
    
    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);

    cout<<"Sorted List of 0s, 1s 2s : without data Replacement "<<endl;
    traverse(head);


}

int main(){
    Node* node1 = new Node(1);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    Node* head = node1;
    cout << "Insert 10 as a head : "<<endl;
    traverse(head);

    InsertAtLast(head,1);
    cout << "Insert 12 At Right or tail Side : "<<endl;
    traverse(head);

    InsertAtBegin(head,0);
    cout << "Insert 13 At Left Side : "<<endl;
    traverse(head);

    cout << "After Inserted at 3rd Position : "<<endl;
    insertAtPosition(head, 1, 2);
    traverse(head);

    cout << "After Inserted at 1st Position : "<<endl;
    insertAtPosition(head, 0, 2);
    traverse(head);

    cout << "After Inserted at 1st Position : "<<endl;
    cout<<"Original Linked List : ";
    insertAtPosition(head, 2,0);
    traverse(head);


    sort012(head);
    DataReplacementNotAllowed(head);

}