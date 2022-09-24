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
void deleteNode(Node* &head, int position){
    Node* prev = head;
    if(position==1){
        head = head->next;
        prev->next = NULL;
        delete prev;
        return;
    }

    Node* tmp = head;
    Node* tmp1 = head;
    int cnt=1;
    while(cnt<position-1){
        tmp = tmp->next;
        cnt++;
    }
    tmp1 = tmp ->next;
    tmp->next = tmp1 -> next;
    tmp1->next = NULL;
    delete tmp1;
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


bool detectLoop(Node* head) {

    //Time Complexity -O(n);
    //Space Complexity -O(n);
    if(head == NULL) {
        return false;
    }

    map<Node*, bool> visited;

    Node* tmp = head;
    while(tmp!=NULL) {
        if(visited[tmp] == true) {
            return true;
        }
        visited[tmp] = true;
        tmp = tmp -> next;
    }
    return false;
}

bool floydCycleDetection(Node* &head) {

    //Time Complexity -O(n);
    //Space Complexity -O(1);
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && slow!=NULL && slow!=fast) {
        fast = fast -> next;
        if(fast!=NULL) {
            fast = fast -> next;
        }
        if(slow == fast) {
            cout<<"Present at : "<<slow ->data <<endl;
            return true;
        }
        
        slow = slow -> next;
    }
    return false;
}
int main(){
    Node* node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
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

    /*
    cout <<"Deleting at Position 5 : "<<endl;
    deleteNode(head, 5);
    traverse(head);

    cout <<"Deleting at Position 3 : "<<endl;
    deleteNode(head, 3);
    traverse(head);
    */

    if(detectLoop(head)) {
       cout<<"Detected, Loop is Present in List "<<endl;
    }
    else{
        cout<<"Detected, Loop is not Present in List " << endl;
    }

   //Using Floyd Cycle Detection Algorithm
   cout<<"Using Floyd Cycle Detection Algorithm "<<endl;
   if(floydCycleDetection(head)) {
       cout<<"Detected, Loop is Present in List "<<endl;
   }
   else{
       cout<<"Detected, Loop is not Present in List " << endl;
   }
}