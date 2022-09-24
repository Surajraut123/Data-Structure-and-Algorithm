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

void predSuccessor(node* root, int k) {
    node* tmp = root;
    int pred = -1;
    int succ = -1;

    while(tmp -> data != k) {
        if(tmp -> data < k) {
            succ = tmp -> data;
            tmp = tmp -> right;
        }
        else{
            pred = tmp -> data;
            tmp = tmp -> left;
        }
    }

    node* leftTree = tmp -> left;
    while(leftTree!=NULL) {
        pred = leftTree -> data;
        leftTree = leftTree -> right;
    }

    node* rightTree = tmp -> right;
    while(rightTree!=NULL) {
        succ = rightTree -> data;
        rightTree = rightTree -> left;
    }

    pair<int , int> ans = make_pair(pred, succ);
    cout<<"Predecessor and Successor Elements are : "<<ans.first<<" "<<ans.second<<endl;

}

int main() {
    node* root = NULL;
    node* ans = takeinput(root);
    levelorderTraversal(ans);
    int i=0;
    cout<<"Enter the Kth Element : "<<endl;
    int k;
    cin>>k;

    predSuccessor(root, k);

}