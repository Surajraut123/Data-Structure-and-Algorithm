#include <iostream>
#include <vector>
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

//Using Space  - O(n);
bool check(Node* head) {
    vector<int> arr;
    Node* tmp = head;
    while(tmp != NULL) {
        arr.push_back(tmp -> data);
        tmp = tmp -> next;
    }

    int s =0;
    int e = arr.size() -1;
    while(s<e) {
        if(arr[s] != arr[e]) {
            return false;
        }
        else{
            s++;
            e--;
        }
    }
    return true;
}
Node* getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head -> next;
    while(fast!=NULL && fast -> next !=NULL) {
        fast = fast -> next -> next;
        slow = slow ->next;
    }
    return slow;
}

Node* reverseList(Node* &tmp) {
    Node* prev = NULL;
    Node* curr = tmp;
    Node* next1 = NULL;
    while(curr != NULL) {
        next1 = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next1;
    }
    return prev;
}

//Using Without Space - O(1)
bool checkPalindrome(Node* head) {

    //step -1
    Node* middle = getMiddle(head);
    Node* tmp = middle ->next;

    //step - 2
    middle -> next = reverseList(tmp);
    Node* head1 = head;
    Node* head2 = middle -> next;

    //step- 3
    while(head2!=NULL) {
        if(head1 -> data != head2 ->data) {
            return false;
        }
        else{
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    }

    //step-4
    tmp = middle ->next;
    middle -> next = reverseList(tmp);
    return true;


}

int main(){
    Node* node1 = new Node(1);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    Node* head = node1;
    cout << "Insert 1 as a head : "<<endl;
    traverse(head);

    InsertAtLast(head,2);
    cout << "Insert 12 At Right or tail Side : "<<endl;
    traverse(head);
    InsertAtLast(head,3);
    cout << "Insert 12 At Right or tail Side : "<<endl;
    traverse(head);
    InsertAtLast(head,3);
    cout << "Insert 12 At Right or tail Side : "<<endl;
    traverse(head);
    InsertAtLast(head,2);
    cout << "Insert 12 At Right or tail Side : "<<endl;
    traverse(head);
    InsertAtLast(head,1);
    cout << "Insert 12 At Right or tail Side : "<<endl;
    traverse(head);

  

    if(check(head)) {
        cout<<"Given Linked List is Palindrome ";
    }
    else{
        cout<<"Linked List is not Palindrome ";
    }
    if(checkPalindrome(head)) {
        cout<<"Given Linked List is Palindrome ";
    }
    else{
        cout<<"Linked List is not Palindrome ";
    }
}