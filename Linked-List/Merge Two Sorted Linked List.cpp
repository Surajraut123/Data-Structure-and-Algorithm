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



Node * solve(Node * first, Node * second) {
    if(first -> next == NULL) {
        first -> next = second;
        return first;
    }
    
    Node * curr1 = first;
    Node * next1 = curr1 -> next;
    Node * curr2 = second;
    Node * next2 = curr2 -> next;
    while(curr2 != NULL && next1 != NULL) {
        if((curr1 -> data <= curr2 -> data) && (next1 ->data >= curr2 -> data)){
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;
            curr1 = curr2;   
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1 -> next;
            if(next1 == NULL) {
                curr1 -> next = curr2;
                return first;
        	}
        }      
    }
    return first;
}

Node * sortTwoLists(Node * first, Node * second)
{
    if(first == NULL) {
        return second;
    }
    if(second == NULL) {
        return first;
    }
    
    if(first -> data <= second -> data){
        return solve(first, second);
    }
    else{
        return solve(second, first);
    }
    
}
