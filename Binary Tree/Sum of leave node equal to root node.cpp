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

pair<bool, int> checksum(node* root) {
    if(root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if(root ->left == NULL && root -> right == NULL) {
        pair<bool, int> p = make_pair(true, root -> data);
        return p;
    }

    pair<bool, int> left = checksum(root -> left);
    pair<bool, int> right = checksum(root -> right);

    int l1 = left.first;
    int l2 = right.first;

    bool l1 = left.second;
    bool l2 = right.second;

    bool ch = root -> data == (l1+l2);

    pair<bool, int> ans;
    if(l1 && l2 && ch) {
        ans.first = true;
        ans.second = root -> data + (l1+l2);
    }
    else{
        ans.first = false;
    }

    return ans;


}

bool isSumTree(node* root)
    {
         return checksum(root).first;
    }
int main(){
    node* root = NULL;
    buildtreeByLevelOrder(root);

    if(isSumTree) {
        cout<<"Yes, Sum is eqaul to root node "<<endl; 
    }


// https://practice.geeksforgeeks.org/problems/sum-tree/1#
}