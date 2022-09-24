#include <iostream>
using namespace std;

class Node {
    public:

    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
    
     ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is Free Now " << endl;
    }
};

void insertAtHead(Node* &head, int data){
    if(head==NULL){
        Node* tmp = new Node(data);
        head = tmp;
    }
    else{
        Node* tmp = new Node(data);
        tmp->next = head;
        head = tmp;
    }
}

void traverseList(Node* head) {
    
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


//Iterative Solution
void reverseLinkedList(Node* &head)
{
    //Singly Linked List
    //Linking to left side

    Node* prev = NULL;
    Node* curr= head;
    Node* forward = NULL;
    while(curr !=NULL) {
        forward = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

void recursive(Node* &head, Node* prev, Node* curr) {
    if(head == NULL) {
        prev = head;
        return;
    }
    
    Node* forward = curr -> next;
    recursive(head, curr, forward);
    curr -> next = prev;

}

void solve(Node* &head, Node* prev, Node* curr){
    if(curr==NULL) {
        head = prev;
        return;
    }
    solve(head, curr, curr->next );
    curr->next = prev;
}


int main() {
    Node* head = NULL;
    
    
    insertAtHead(head, 11);
    traverseList(head);
    
    insertAtHead(head, 12);
    traverseList(head);
    
    insertAtHead(head, 13);
    traverseList(head);
    
    insertAtHead(head, 14);
    traverseList(head);
    
    insertAtHead(head, 15);
    traverseList(head);
    
    cout<<"Original Linked List : ";
    traverseList(head); 
    
    cout << "Reversed Linked List : ";
    reverseLinkedList(head);
    traverseList(head);
    
    cout<<"Reverse Linked List Using Recursion : ";
    solve(head, NULL, head);
    traverseList(head);

    recursive(head, NULL, head);
    
    
    
}