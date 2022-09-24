#include<iostream>
using namespace std;

class node{
    public:

    int data;
    node* left;
    node* right;

    node(int data) {
        this -> data = data;
        this -> right = NULL;
        this -> left = NULL;
    }
};

node* insertAtBST(node* root, int data) {
    if(root == NULL) {
        root = new node(data);
        return root;
    }

    if(data > root -> data) {
        root -> right = insertAtBST(root -> right, data);
    }
    else{
        root ->left = insertAtBST(root -> left, data);
    }
    return root;
}

void takeinput(node* &root) {
    int data;
    cin>> data;

    while(data != -1) {
        root = insertAtBST(root, data);
        cin >> data;
    }
}


node* maxValue(node* root) {
    node* tmp = root;
    while(tmp -> right != NULL) {
       tmp = tmp -> right;
    }
    return tmp;
}
node* minValue(node* root) {
    node* tmp = root;
    while(tmp -> left != NULL) {
        tmp = tmp ->left;
    }
    return tmp;
}
int main() {
    node* root = NULL;
    takeinput(root);
    
    node* maxValu = maxValue(root);
    cout<<"Max : "<<maxValu -> data<<endl;
    node* minValu = minValue(root);
    cout<<"Min : "<<minValu -> data;
}