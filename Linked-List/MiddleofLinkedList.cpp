#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void InsertDataattail(Node* &head, int data)  {

    //List contain empty node
    if(head==NULL) {
        Node* tmp = new Node(data);
        head = tmp;
    }

    //List contain one node only
    else if(head->next==NULL){
        Node* curr = head;
        Node* tmp = new Node(data);
        tmp->next = curr->next;
        curr->next = tmp;
    }
    //List contain more than one node
    else{
        Node* tmp = head;
        while(tmp->next!=NULL) {
            tmp = tmp->next;
        }
        Node* tmp1 = new Node(data);
        tmp1->next = tmp->next;
        tmp->next = tmp1;
    }
}


void traverseList(Node* head) {
    do{
        cout << head ->data<< " ";
        head = head->next;
    }while(head!=NULL);
    cout<<endl;
}


int getLength(Node* head ){
    int cnt=0;
    if(head==NULL){
        return cnt;
    }
    do{
        cnt++;
        head = head->next;
    }while(head!=NULL);

    return cnt;
}

void getMiddleListApproach1(Node* head) {
    int ans = getLength(head) / 2;

    while(ans--) {
        head = head -> next;
    }
    cout << "Middle of Linked List is " << head -> data;

}

void getMiddleNodeApproach2(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL) {
        fast = fast -> next;
        if(fast!=NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;
    }

    cout << "Middle Node Linked List Approach-2: " << slow->data;
}

int main(){
    Node* head = NULL;
    
    InsertDataattail(head, 11);
    cout << "Element 11 is Inserted : ";
    traverseList(head);
    InsertDataattail(head, 12);
    cout << "Element 12 is Inserted : ";
    traverseList(head);
    InsertDataattail(head, 13);
    cout << "Element 13 is Inserted : ";
    traverseList(head);
    InsertDataattail(head, 14);
    cout << "Element 14 is Inserted : ";
    traverseList(head);
    InsertDataattail(head, 15);
    cout << "Element 15 is Inserted : ";
    traverseList(head);

    getMiddleListApproach1(head);
    cout<<endl;
    getMiddleNodeApproach2(head);

}