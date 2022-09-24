#include <iostream>
using namespace std;

class Node {
    public :

    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
            this -> next = NULL;
    }
};


Node* floydCycleList(Node* &head) {
    if(head==NULL) {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(slow!=NULL && fast!=NULL) {
        fast = fast -> next;
        if(fast!=NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;
        if(slow == fast) {
            cout<<"Loop is Detected in List"<<endl;
            return slow;
        }
    }
    cout<<"No loop is in List"<<endl;
    return NULL;    
}

Node* BeginningNode(Node* &head) {
    if(head == NULL) {
        return NULL;
    }
    
    Node* tmp = floydCycleList(head);
    if(tmp == NULL) {
        return NULL;
    }
    Node* slow = head;
    while(slow != tmp) {
        slow = slow -> next;
    	tmp = tmp -> next;
    }
    cout<<"Beginning Node of Cycle/Loop in list is : "<<slow -> data<<endl;
    return slow;
}

void removeLoop(Node *head)
{
    Node* flow = BeginningNode(head);
    if(flow == NULL) {
        cout<<"List is Singly"<<endl;
    }
    Node* tmp = flow;
    
    while(tmp -> next != flow) {
        tmp = tmp -> next;
    }
    tmp ->next = NULL;
    cout<<"Loop of List is Removed Now : "<<endl;
}


void traverseList(Node *head, Node* start)
{
    Node* tmp = head;
    int cnt=2;
    while(cnt>0) {
        while(tmp!=start) {
            cout<<tmp -> data << " ";
            tmp = tmp -> next;
        }
        cout<<tmp -> data << " ";
        tmp = tmp -> next;
        cnt--;
    }
    cout<<endl;
}


int main() {
    Node* head = new Node(10);;
    Node* second = new Node(11);;
    Node* third = new Node(12);;
    Node* fourth = new Node(13);;
    
    head->next = second;
    
    second->next = third;
    
    third->next = fourth;
    
    fourth->next = second;
    
    cout<<"Circular Linked List : "<<endl;
    Node* tmp = BeginningNode(head);
    traverseList(head , tmp);

    cout<<"After Detecting and removing Loop : "<<endl;
    removeLoop(head);

}
