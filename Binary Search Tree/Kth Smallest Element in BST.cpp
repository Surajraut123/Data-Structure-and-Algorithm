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


int kthSmallestElement(node* root,int &i, int k) {
    if(root == NULL) {
        return -1;
    }

    int left = kthSmallestElement(root -> left, i, k);
    if(left!=-1) {
        return left;
    }

    i++;

    // for Kth Largest Element we can Use
    // (n-k)+1;
    if(i==k) {
        return root -> data;
    }

    return kthSmallestElement(root -> right, i , k);
}
int main() {
    node* root = NULL;
    node* ans = takeinput(root);
    levelorderTraversal(ans);
    int i=0;
    cout<<"Enter the Kth Element : "<<endl;
    int k;
    cin>>k;
    cout<<"Kth Smallest Element : "<<kthSmallestElement(root, i, k);

}