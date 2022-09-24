#include <iostream>
#include <queue>
using namespace std;

class node{
    public :
    int data;
    node* left;
    node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this-> right = NULL;
    }

};

void BuildTreeByLevelOrder(node* &root) {
    queue<node*> q;
    cout<<"Enter the root Node : "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()) {
        node* tmp = q.front();
        q.pop();

        cout<<"Enter the Left of "<< tmp -> data <<endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1) {
            tmp -> left = new node(leftData);
            q.push(tmp -> left);
        }

        cout<<"Enter the right of " << tmp -> data << endl;
        int rightData;
        cin >> rightData;
        if(rightData != -1) {
            tmp -> right = new node(rightData);
            q.push(tmp -> right);
        }
    }
}

void levelOrderTree(node* &root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* tmp = q.front();
        q.pop();

        if(tmp == NULL) {
            if(!q.empty()) {
                q.push(NULL);
            }
            cout<<endl;
        }
        else{
            cout << tmp -> data << " ";

            if(tmp -> left) {
                q.push(tmp -> left);
            }
            if(tmp -> right) {
                q.push(tmp -> right);
            }
        }
    }
}

void inorder(node* &root,int &cnt) {
    if(root == NULL) {
        return;
    }

    inorder(root ->left, cnt);
    if(root -> left == NULL && root -> right == NULL) {
        cnt++;
        cout<<root -> data<<" ";
    }
    inorder(root -> right, cnt);
}

void countLeaf(node* root) {
    int count = 0;
    cout<<"Leaf Node are : ";
    inorder(root, count);
    cout<<endl;
    cout<<count;

}

int main() {
    node* root = NULL;
    BuildTreeByLevelOrder(root);
    levelOrderTree(root);

    cout<<"Total Number of Leaf node : ";
    countLeaf(root);



}