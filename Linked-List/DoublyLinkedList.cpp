#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev,*next;

    Node(int data){
        this->data = data;
        this->prev=NULL;
        this->next = NULL;
    }
};

void traverse(Node* &head) {
    Node* tmp = head;
    while(tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp -> next;
    }
    cout<<endl;
}
void insertAtHead(Node* &head, int data){

    if(head==NULL){
        Node* tmp = new Node(data);
        head = tmp;
    }
    else{
        Node* tmp = new Node(data);
        tmp->next = head;
        tmp->prev = NULL;
        head->prev = tmp;
        head = tmp;
    }
    
}

void insertAtTail(Node* &head, int data){

    if(head==NULL){
        Node* tmp = new Node(data);
        head = tmp;
    }
    else{
         Node* tail = new Node(data);
        Node* tmp = head;

        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next = tail;
        tail->prev = tmp;
        tail->next = NULL;
    }
   
}

int getLength(Node* head){
    int len=0;
    Node* tmp = head;
    while(tmp != NULL) {
        len++;
        tmp = tmp -> next;
    }
    return len;
}

void insertAtPosition(Node* &head, int position, int data){
    int p = getLength(head);
    if(position==1){
        insertAtHead(head,data);
    }
    else if(p<position){
        insertAtTail(head, data);
        
    }

    else{
        Node* tmp = new Node(data);
        Node* tmp1 = head;
        int cnt=1;
        while(cnt < position-1){
            tmp1 = tmp1->next;
            cnt++;
        }
        tmp->next = tmp1->next;
        tmp1->next->prev = tmp;
        tmp1->next = tmp;
        tmp->prev = tmp1;
    }
}


void deleteAtPosition(Node* &head, int position){
    Node* tmp = head;
    int cnt = 1;
    int p = getLength(head);
    if(position==1){
        head = head->next;
        tmp->next->prev = NULL;
        tmp->next = NULL;
        delete tmp;
    }
    else if(p==position){
        while(tmp->next->next!=NULL) {
            tmp = tmp->next;
        }
        tmp->next = NULL;
    }
    else {
        while(cnt < position-1){
            tmp = tmp -> next;
            cnt++;
        }
        tmp->next->next->prev = tmp;
        tmp->next = tmp->next->next;
    }
    
    
}
int main(){
    // if head starting head is null
    Node* head = NULL;
    // Node* node1 = new Node(10);
    // Node* head = node1;
    traverse(head);

    cout<<"Length of Linked List : "<<getLength(head)<<endl;;

    insertAtHead(head,11);
    cout<<"Inserted Element at Head "<<endl;
    traverse(head);

    insertAtTail(head,12);
    cout<<"Inserted Element at Tail "<<endl;
    traverse(head);

    insertAtPosition(head,3,13);
    cout<<"Inserted Element at Position "<<endl;
    traverse(head);

    cout<<"Deleted Element at Position "<<endl;
    deleteAtPosition(head, 1);
    traverse(head);




}