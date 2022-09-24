#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void buildtreeByLevelOrder1(node* &root) {
    queue<node*> q; 
    int data;
    cout<<"Enter the Root Node data "<<endl;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()) {
        node* tmp = q.front();
        q.pop();

        cout<<"Enter the Left Node of "<<tmp ->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1) {
            tmp -> left = new node(leftData);
            q.push(tmp -> left);
        }
        cout<<"Enter the right Node of "<< tmp -> data <<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1) {
            tmp -> right = new node(rightData);
            q.push(tmp -> right);
        }

    }
}

void buildtreeByLevelOrder2(node* &root) {
    queue<node*> q; 
    int data;
    cout<<"Enter the Root Node data "<<endl;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()) {
        node* tmp = q.front();
        q.pop();

        cout<<"Enter the Left Node of "<<tmp ->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1) {
            tmp -> left = new node(leftData);
            q.push(tmp -> left);
        }
        cout<<"Enter the right Node of "<< tmp -> data <<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1) {
            tmp -> right = new node(rightData);
            q.push(tmp -> right);
        }

    }
}


//T.C = O(n);
//S.C = O(height of tree);
bool identical(node* r1, node* r2){
        if(r1 == NULL && r2 == NULL) {
            return true;
        }
        if(r1 != NULL && r2 == NULL) {
            return false;
        }
        if(r1 == NULL && r2 != NULL) {
            return false;
        }

        bool left = identical(r1 -> left, r2 -> left);
        bool right = identical(r1 -> right, r2 -> right);


        bool value = r1 -> data == r2 -> data;
        if(left && right && value) {
            return true;
        }
        else{
            return false;
        }
}

int main(){
    node* r1 = NULL;
    node* r2 = NULL;
    buildtreeByLevelOrder1(r1);
    buildtreeByLevelOrder2(r2);

    if(identical(r1, r2)) {
        cout<<"Identical";
    }
    else{
        cout<<"Not Identical";
    }
    


}