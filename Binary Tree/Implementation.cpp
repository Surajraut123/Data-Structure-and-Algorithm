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


node* buildTree(node* root) {
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data==-1) {
        return NULL;
    }

    cout<<"Enter the data in Left "<<data<<endl;
    root -> left = buildTree(root->left);

    cout<<"Enter the data in Right "<<data<<endl;
    root -> right = buildTree(root -> right);

    return root;

}


void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);

    //For display Level order in proper format
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        if(temp ==NULL) {//purana level complete traverse is done
            cout<<endl;
            //queue still have some child nodes
            //We Used Here a Separator
            //1 -1 3 5 -1 7 11 
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else{
            cout<<temp -> data <<" ";
            if(temp -> left) {
                q.push(temp ->left);
            }
            if(temp -> right) {
                q.push(temp ->right);
            }
        }
    }
}


void inOrderTraversal(node* root) {
    if(root == NULL) {
        return;
    }

    inOrderTraversal(root -> left);
    cout<<root -> data << " ";
    inOrderTraversal(root -> right);
}

void PreOrderTraversal(node* root) {
    if(root == NULL) {
        return;
    }

    cout<<root -> data << " ";
    PreOrderTraversal(root -> left);
    PreOrderTraversal(root -> right);
}

void PostTraversal(node* root) {
    if(root == NULL) {
        return;
    }

    PostTraversal(root -> left);
    PostTraversal(root -> right);
    cout<<root -> data << " ";
}


void buildtreeByLevelOrder(node* &root) {
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
int main(){
    node* root = NULL;
    //root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //levelordertraversal
    
    cout<<"Printintg Level order traversal "<<endl;
    levelOrderTraversal(root);

    cout<<"InOrder Traversal : ";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"PreOrder Traversal : ";
    PreOrderTraversal(root);
    cout<<endl;

    cout<<"PostOrder Traversal : ";
    PostTraversal(root);
    cout<<endl;

    buildtreeByLevelOrder(root);
    levelOrderTraversal(root);

}