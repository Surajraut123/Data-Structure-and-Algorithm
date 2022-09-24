#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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

void insertNode(Node *&tail, int element, int d)
{
    // Here element is used forInsert after that Element and
    // D is used for Insert that value;

    // Empty List
    // Assuming element is not present in list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }

    else
    {
        // No Empty List
        // Assuming at least one element is present in list
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *tmp = new Node(d);
        tmp->next = curr->next;
        curr->next = tmp;
        tail = tmp;
    }
}

void traverseList(Node *tail)
{
    Node *tmp = tail;
    if (tail == NULL)
    {
        cout << "List is Empty" << endl;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != tmp);
    cout << endl;
}

void deleteNode(Node *&tail, int element)
{

    if (tail == NULL)
    {
        cout << "List is Empty : " << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        if (curr == prev)
        {
            tail = NULL;
        }
        //>=2 ki Linked List
        if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

bool isCircularList(Node* head) {
    if(head == NULL) {
        return true;
    }

    Node* tmp = head -> next;
    while(tmp!=NULL && tmp!=head) {
        tmp = tmp -> next;
    }
    if(tmp==head) {
        return true;
    }

    return false;
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
            cout<<"Present on "<< tmp->data<<endl;
            return true;
        }
        visited[tmp] = true;
        tmp = tmp -> next;
    }
    return false;
}

//Floyds Cycle Detection Algorithm
bool floydCycleDetection(Node* &head) {

    //Time Complexity -O(n);
    //Space Complexity -O(1);
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && slow!=NULL) {
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

//Here List is Already Circular Linked List 
//So that slow is always equal to intersection.

// void getStartingNode(Node* head) {
//     if(head == NULL) {
//         return;
//     }

//     Node* fast = head;
//     Node* slow = head;
//     Node *intersection = NULL;
//     while(fast != NULL && slow!=NULL) {
//         fast = fast -> next;
//         if(fast!=NULL) {
//             fast = fast -> next;
//         }
//         if(fast==slow){
//             intersection = slow;
//             break;
//         }
//         slow = slow -> next;
//     }
//     slow = head;
//     while(slow!=intersection) {
//         slow = slow -> next;
//         intersection = intersection -> next;
//         if(intersection==slow) {
//             cout<<"Starting Node of Cycle within a Linked List is "<<slow->data<<endl;
//         }
//     }
// }


int main()
{
    Node *tail = NULL;
    cout << "Inserting Element in an Empty Linked List : ";
    insertNode(tail, 1, 12);
    traverseList(tail);

    cout<<"Inserting Element in an Linked List after the value of 12 : ";
    insertNode(tail, 12, 13);
    traverseList(tail);
    /*
    cout<<"Inserting Element in an Linked List after the value of 13 : ";
    insertNode(tail, 13, 14);
    traverseList(tail);

    //Now we Inserting in a middle of list Linked
    cout<<"Inserting Element in an Linked List after the value of 13 : ";
    insertNode(tail, 13, 20);
    traverseList(tail);

    cout<<"Inserting Element in an Linked List after the value of 12 : ";
    insertNode(tail, 14, 19);
    traverseList(tail);

    Deleteing Node
    For Deleting First Node
    cout << "Deleting a 20 Node :";
    deleteNode(tail, 12);
    traverseList(tail);

    cout << "Deleting a 20 Node :";
    deleteNode(tail, 20);
    traverseList(tail);
    */

    if(isCircularList(tail)) {
        cout<<"List is a Circular Linked List "<<endl;
    }
    else{
        cout<<"Not A Circular Linked List " << endl;
    }

        //Using Map
    if(detectLoop(tail)) {
        cout<<"Detected, Loop is Present in List "<<endl;
    }
    else{
        cout<<"Detected, Loop is not Present in List " << endl;
    }

    //Using Floyd Cycle Detection Algorithm
    cout<<"Using Floyd Cycle Detection Algorithm "<<endl;
    if(floydCycleDetection(tail)) {
        cout<<"Detected, Loop is Present in List "<<endl;
    }
    else{
        cout<<"Detected, Loop is not Present in List " << endl;
    }

    
}