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

int heightofBinaryTree(node* root) {
    if(root == NULL) {
        return 0;
    }
    int left = heightofBinaryTree(root -> left);
    int right = heightofBinaryTree(root -> right);

    int ans = max(left, right)+1;
    return ans;
}
int main(){
    node* root = NULL;
    //root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //levelordertraversal

    
    buildtreeByLevelOrder(root);
    int p=heightofBinaryTree(root);
    cout<<"Height of Binary Tree : "<<p<<endl;

}