#include <bits/stdc++.h>
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

void removeDuplicates(Node *head)
{
    Node* curr = head;
    while(curr != NULL) {
        Node* go = curr;
        Node* tmp = curr -> next;
        while(tmp != NULL) {
            if(tmp -> data == curr -> data) {
                go -> next = tmp -> next;
                tmp -> next = NULL;
                delete tmp;
                tmp = go -> next;
            }
            else{
                go = go -> next;
                tmp = tmp -> next;
            }
        }
        curr = curr -> next;
    }
    traverse(head);
}


//Second Approach
void removedup(Node* head) {
    Node* curr = head;
    while(curr != NULL) {
        if((curr->next!=NULL) && curr -> data == curr -> next -> data) {
            Node* forward = curr -> next -> next;
            Node* del = curr -> next;
            delete(del);
            curr -> next = forward;
        }
        else{
            curr = curr -> next;
        }
    }
    traverse(head);
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

void removeDuplicates(Node *start)
{
    unordered_set<int> seen;
 
    /* Pick elements one by one */
    struct Node* curr = start;
    struct Node* prev = NULL;
    while (curr != NULL) {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete (curr);
        }
        else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
    traverse(start);
}




int main(){
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
    insertAtPosition(head, 1, 12);
    traverse(head);

    cout << "After Inserted at 1st Position : "<<endl;
    insertAtPosition(head, 3, 13);
    traverse(head);

    cout<<"After Removing Duplicates from UnSorted Linked List : " <<endl;
    removeDuplicates(head);
}