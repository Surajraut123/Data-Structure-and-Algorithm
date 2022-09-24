#include <iostream>
#include <map>
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
    tmp1 -> next =NULL;
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

void traverse(Node* &head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}

void getStartingNode(Node* head) {
    if(head == NULL) {
        return;
    }

    Node* fast = head;
    Node* slow = head;
    Node *intersection = NULL;
    while(fast != NULL && slow!=NULL) {

        fast = fast -> next;
        if(fast!=NULL) {
            fast = fast -> next;
        }
        if(fast==slow){
            intersection = slow;
            break;
        }
        slow = slow -> next;
    }
    slow = head;
    if(slow == intersection){
        cout<<slow -> data;
    }
    while(slow!=intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
        if(intersection==slow) {
            cout<<"Starting Node of Cycle within a Linked List is "<<slow->data<<endl;
            break;
        }
    }
}


int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    cout << "Insert 10 as a head : "<<endl;
    traverse(head);

    InsertAtBegin(head,13);
    cout << "Insert 13 At Left Side : "<<endl;
    traverse(head);

    cout << "Insert 11 At Left Side : "<<endl;
    InsertAtBegin(head, 11);
    traverse(head);

    cout << "After Inserted at begin Position : "<<endl;
    InsertAtBegin(head, 15);
    traverse(head);

    Node* tmp = head;
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }
    tmp->next = head -> next;

    InsertAtLast(head,12);
    cout << "Insert 12 At Right or tail Side : "<<endl;
    // traverse(head);

    cout<<"Starting Node is :"<<endl;
    getStartingNode(head);

}