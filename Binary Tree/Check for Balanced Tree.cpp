#include<iostream>
#include<queue>
#include<cmath>
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

int height(node* root) {
    if(root == NULL) {
        return 0;
    }
    int left = height(root -> left);
    int right = height(root -> right);

    int ans = max(left, right)+1;
    return ans;
}
//T.C = O(n*n);
//S.C = O(height of tree)
bool balancedTree(node* root) {
    if(root == NULL) {
        return true;
    }
        
    bool left = balancedTree(root -> left);
    bool right = balancedTree(root -> right);
    bool cond = abs(height(root -> left) - height(root -> right)) <=1;
        
    if(left && right && cond) {
        return true;
    }else{
        return false;
    }
}

//T.C = O(n);
//S.C = O(height of tree);

pair<bool, int> balanced(node* root) {
        if(root == NULL) {
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }
        
        pair<bool, int> leftans = balanced(root -> left);
        pair<bool, int> rightans = balanced(root -> right);
        
        bool cond = abs(leftans.second - rightans.second) <=1;
        
        
        pair<bool, int> ans;
        
        if(leftans.first && rightans.first && cond) {
            ans.first = true;
            ans.second = max(leftans.second, rightans.second) + 1;
        }
        
        return ans;
    }

bool isBalanced(node *root)
{        
    return balanced(root).first;
}

int main(){
    node* root = NULL;
    //root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //levelordertraversal

    
    buildtreeByLevelOrder(root);
    int p = height(root);
    cout<<"Height of Binary Tree : "<<p<<endl;

    if(balancedTree(root)) {
        cout<<"Balanced ";
    }
    else{
        cout<<"Not Balanced";
    }

    if(isBalanced(root)) {
        cout<<"Balanced ";
    }
    else{
        cout<<"Not Balanced";
    }


}