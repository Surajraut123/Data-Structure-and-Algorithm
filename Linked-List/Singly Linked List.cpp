#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;

  node(int data) {
    this -> data = data;
    this -> next = NULL;
  }
};

void insertatPosition(node* &head,int data, int position) {
  node* tmp = head;
  node* curr = NULL;
  int reach=0;
  while(reach!=position-1) {
    curr = tmp;
    tmp = tmp -> next;
    reach++;
  }
  node* newNode = new node(data);
  curr -> next = newNode;
  newNode -> next = tmp;
}

void insertatEnd(node* &head, node* &tail, int data) {
  if(head == NULL){
    node* tmp = new node(data);
    head = tmp;
    tail = tmp;
  }
  else{
    node* tmp = new node(data);
    tail -> next = tmp;
    tail = tmp;
  }
}

void insertatBeginning(node* &head, int data) {
  if(head==NULL) {
    node* tmp = new node(data);
    head = tmp;
  }
  else{
    node* tmp = new node(data);
    tmp -> next = head;
    head = tmp;
  }
}

void deleteFromBeginning(node* &head) {
  if(head == NULL) {
    cout<<"List is Empty Nothing to delete anything"<<endl;
  }
  else if(head -> next == NULL) {
    head = NULL;
    cout<<"It contain only ne node "<<endl;
  }
  else{
    node* tmp = head;
    head = head -> next;
    delete tmp;
  }
}

void deletefromEnd(node* &head) {
  if(head == NULL) {
    cout<<"List is Empty Nothing to delete anything"<<endl;
  }
  else if(head -> next == NULL) {
    head = NULL;
    cout<<"It contain only one node "<<endl;
  }
  else{
    node* tmp = head;
    node* curr = NULL;
    while(tmp -> next != NULL) {
      curr = tmp;
      tmp = tmp -> next;
    }
    curr -> next = NULL;
    delete tmp;
  }
}

void deletefromPosition(node* &head, int position) {

   node* prev = head;
    if(position==1){
        head = head->next;
        prev->next = NULL;
        delete prev;
        return;
    }

  
  node* tmp = head;
  node* curr = NULL;
  int reach=1;
  while(reach<position-1) {
    tmp = tmp -> next;
    reach++;
  }
  curr = tmp -> next;
  tmp -> next = curr -> next;
  curr -> next = NULL;
  delete curr;
}

void print(node* head) {
  if(head==NULL) {
    cout<<"Nothing to Print Kindly insert the data in a Linked List"<<endl;
  }
  else{
    
    while(head!=NULL) {
    cout<<head -> data<<" ";
    head = head -> next;
    }
  }  
}


int main() {
    node* head = NULL;
    node* tail = NULL;
    int n;
    cout<<"Enter the Total node to insert in a Linked List"<<endl;
    cin>>n;
    cout<<endl;
    cout<<"Enter what Operation you want to perform : "<<endl<< " 1 : Insert at Beginning "<<endl<< " 2 : Insert at End" <<endl<<" 3 : InsertatPosition" <<endl<<" 4 : Delete From Beginning "<<endl<<" 5 : Delete From End "<<endl<< " 6 : Delete From an Position"<<endl<<endl;

    bool check = true;

    while(check) {

        int userInput;
        cout << "Enter Your Choice : "<<endl;
        cin>>userInput;

        bool haveLinkedList = false;
        if(userInput == 1 || userInput ==2 || userInput==3){
            cout<<"Insert the Data in a Linked List "<<endl<<endl;
            for(int i=0; i<n; i++) {
              int data;
              cout<<"Enter the Data : ";
              cin>>data;
              haveLinkedList = true;
              switch(userInput) {

                  case 1 : insertatBeginning(head, data);break;
                  case 2 : insertatEnd(head, tail, data);break;
                  case 3 : 
                      int position;
                      cout << "Enter the Position : ";
                      cin>>position;
                      insertatPosition(head, data, position);
                      break;
              }

              if(i==n-1) {
                cout<<endl<<"You want enter more data on a Linked List"<<endl;
                cout<<"If yes print 1 otherwise enter any key to exit "<<endl;
                int check;
                cin>>check;
                if(check==1) {
                    cout<<"Enter how many nodes want to enter"<<endl;
                    int total;
                    cin>>total;
                    n = n + total;
                }
              }
            }
          cout<<endl<<"Inserted Linked List "<<endl;
          print(head);
          cout<<endl;
        }
        cout<<endl;
      
        if(haveLinkedList) {
            
            bool interest = true;
            while(interest){
              cout << "Enter Your Choice : To Perform Deletion Operation "<<endl;
              cout << " 4 : Delete From Beginning "<<endl<<" 5 : Delete From End "<<endl<< " 6 : Delete From an Position"<<endl;
              cout<<"Enter your choice : "<<endl;
              cin>>userInput;
              switch(userInput) {
          
                case 4 : deleteFromBeginning(head); break;
                case 5 : deletefromEnd(head); break;
                case 6 : 
                        int position;
                        cout << "Enter the Position : ";
                        cin>>position;
                        deletefromPosition(head, position);
                        break;
            
                default : cout<<"You Entered wrong Choice "<<endl;
              }
              cout<<endl;
              cout<<"Printing Deleted Singly Linked List "<<endl;
              print(head);
              cout<<endl<<endl;
              cout<<"Interested To perform more Deletion operation : "<<endl;
              cout << "Enter Yes for 1 otherwise enter random key  : "<<endl;
              int input;
              cin>>input;
              if(input!=1) {
                  interest = false;
              }
            }
            cout << " Want to Implement new Linked List : " << endl;
            cout << "Enter Yes for 1 otherwise enter random key  : ";
            int input;
            cin>>input;
            if(input!=1) {
                check = false;
            }
        
        }
        else{
            cout<<"You Don't have any data to perform your operation : ";
            cout<<"Please Insert a Data in a Linked List "<<endl;
        }
            
    }  

    // cout<<"Printing Operationalized Singly Linked List "<<endl;
    // print(head);
}