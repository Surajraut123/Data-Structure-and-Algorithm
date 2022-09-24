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

node* insertatBST(node* root, int data) {
    if(root == NULL) {
        root = new node(data);
        return root;
    }

    if(data < root -> data ) {
        root -> left = insertatBST(root -> left, data);
    }
    else{
        root -> right = insertatBST(root -> right, data);
    }

    return root;
}

void takeinput(node* &root ){
    int data;
    cin>>data;

    while(data !=-1) {
        root = insertatBST(root, data);
        cin>> data;
    }

}

void levelwiseTraversal(node* root) {
    queue<node*> q;
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
            if(tmp -> right ) {
                q.push(tmp -> right);
            }
        }
    }
}

node* minValue(node* root) {
    while(root -> left != NULL) {
        root = root ->left;
    }
    return root;
}
node* maxValue(node* root) {
    while(root -> right != NULL) {
        root = root ->right;
    }
    return root;
}

node* deleteFromBST(node* root, int k) {
    if(root == NULL) {
        return NULL;
    }

    if(root -> data == k) {
        // 0 child

        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if(root -> left !=NULL && root -> right == NULL) {
            node* tmp = root -> right;
            delete root;
            return tmp;
        }

        // right child
        if(root -> right !=NULL && root -> left == NULL) {
            node* tmp = root -> left;
            
            delete root;
            return tmp;
        }
        
        
        // 2 child
        if(root -> right != NULL & root -> left != NULL) {
            int mini = minValue(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, k);
            return root;
        }

    }
    else if( k > root ->data){
        root -> right = deleteFromBST(root -> right, k);
        return root;
    }
    else{
        root ->left = deleteFromBST(root -> left, k);
        return root;
    }
}

int main() {
    node* root = NULL;
    takeinput(root);
    levelwiseTraversal(root);

    int mini = minValue(root) -> data;
    int maxi = maxValue(root) -> data;
    int key;
    cout<<"Enter the data to delete : "<<endl;
    cin>> key;
    deleteFromBST(root, key);
    levelwiseTraversal(root);
}

