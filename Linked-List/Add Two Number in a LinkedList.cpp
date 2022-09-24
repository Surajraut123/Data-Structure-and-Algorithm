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

void traverse(Node* &head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}

Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* tmp = NULL;
        while(curr !=NULL) {
            tmp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    
void insertAtTail(Node* &head, Node* &tail, int value) {
    Node* tmp = new Node(value);
    if(head == NULL) {
        head = tmp;
        tail = tmp;
    }
    else{
        tail -> next = tmp;
        tail = tmp;
    }
}

Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverseList(first);
        second = reverseList(second);
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        int carry =0 ;
        while(first!=NULL && second !=NULL) {
            int sum = first -> data + second -> data + carry;
            int digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            first = first -> next;
            second= second -> next;
        }
        
        while(first!= NULL) {
            int sum = first -> data + carry;
            int digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum /10;
            first = first -> next;
        }
        while(second!= NULL) {
            int sum = second -> data + carry;
            int digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum /10;
            second = second -> next;
        }
        
        while(carry!=0) {
            int sum = carry;
            int digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
        }
        
        ansHead = reverseList(ansHead);
        return ansHead;
        
    }


int main(){

    //First list
    Node* node1 = new Node(10);
    Node* head = node1;
    cout << "Insert 10 as a head : "<<endl;
    traverse(head);

    InsertAtLast(head,12);
    cout << "Insert 12 At Right or tail Side : "<<endl;
    traverse(head);

    InsertAtBegin(head,13);
    cout << "Insert 13 At Left Side : "<<endl;
    traverse(head);

    cout << "After Inserted at 3rd Position : "<<endl;
    insertAtPosition(head, 3, 11);
    traverse(head);

    cout << "After Inserted at 1st Position : "<<endl;
    insertAtPosition(head, 1, 14);
    traverse(head);

    cout << "After Inserted at 1st Position : "<<endl;
    insertAtPosition(head, 3, 15);
    traverse(head);


    //Second List
    Node* node2 = new Node(10);
    Node* head1 = node2;
    cout << "Insert 10 as a head : "<<endl;
    traverse(head1);

    InsertAtLast(head1,12);
    cout << "Insert 12 At Right or tail Side : "<<endl;
    traverse(head1);

    InsertAtBegin(head1,13);
    cout << "Insert 13 At Left Side : "<<endl;
    traverse(head1);

    cout << "After Inserted at 3rd Position : "<<endl;
    insertAtPosition(head1, 3, 11);
    traverse(head1);

    cout << "After Inserted at 1st Position : "<<endl;
    insertAtPosition(head1, 1, 14);
    traverse(head1);

    cout << "After Inserted at 1st Position : "<<endl;
    insertAtPosition(head1, 3, 15);
    traverse(head1);

    cout<<"Addition of list is :"<<endl;
    Node* ans = addTwoLists(head, head1);
    traverse(ans);

    

}