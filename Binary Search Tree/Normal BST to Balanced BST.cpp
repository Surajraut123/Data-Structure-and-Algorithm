#include<iostream>
#include<queue>
#include<vector>
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

void inorder(node* root, vector<int> &in) {
    if(root == NULL) {
        return;
    }

    inorder(root -> left, in);
    in.push_back(root ->data );
    inorder(root -> right, in);
}


node* solve( int i, int j, vector<int> &ans) {
    if(i>j) {
        return NULL;
    }

    // we know inorder is Sorted form , we taken first mid then left and right part is managed
    int mid = (i+j) /2;
    node* tmp = new node(ans[mid]);
    tmp -> left = solve(i, mid-1, ans);
    tmp -> right = solve(mid+1, j, ans);
    return tmp;
}

node* balanced(node* root) {
    vector<int> ans;
    inorder(root, ans);

    //1 2 3 4 5 6 7 - Unbalanced BST
    //i           j - initially
    return solve(0, ans.size()-1, ans);

    
}
int main() {
    node* root = NULL;
    node* ans = takeinput(root);
    levelorderTraversal(ans);

    node* ans = balanced(root);
  
    
       

}