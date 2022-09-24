#include<iostream>
#include<queue>
using namespace std;


class node{
    public:

    int data;
    node* left;
    node* right;

    node(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};


node* insertAtBST(node* root, int data) {
    if(root == NULL) {
        root = new node(data);
        return root;
    }

    if(data < root -> data) {
        root -> left = insertAtBST(root -> left, data);
    }
    else{
        root -> right = insertAtBST(root -> right, data);
    }

    return root;
}
node* takeinput(node* &root) {
    int data;
    cin>>data;
    while(data !=-1) {
        root = insertAtBST(root, data);
        cin>> data;
    }
    return root;
}


void levelorderTraversal(node* root) {
    queue<node* > q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* tmp = q.front();
        q.pop();

        if(tmp == NULL) {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else{
            cout<<tmp -> data << " ";
            if(tmp -> left) {
                q.push(tmp -> left);
            }
            if(tmp -> right) {
                q.push(tmp -> right);
            }
        }
    }
}

node* LCAinaBST(node* root, node* P, node* Q)
{
	while(root != NULL) {
        if(root->data > P->data && root->data > Q->data){
            root = root -> left;
        }
        else if(root->data < P->data && root->data < Q->data){
            root = root -> right;
        }
        else{
            return root;
        }
    }    
}

int main() {
    node* root = NULL;
    node* ans = takeinput(root);
    levelorderTraversal(ans);

    cout<<"Enter the two value ot get LCA : "<<endl;
    int a,b;
    cin>>a>>b;
    node* p =new node(a);
    node* q =new node(b);

    node* ans = LCAinaBST(root, p, q);
    

}