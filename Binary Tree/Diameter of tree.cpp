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

    int ans = max(left, right) + 1;
    return ans;
}

// T.C = O(n^2);
// S.C = O(height of tree);
// Visiting Each Node twice for diameter and Height.

int diameter(node* root) {
    if(root == NULL) {
        return 0;
    }

    int op1 = diameter(root -> left);
    int op2 = diameter(root -> right);
    int op3 = heightofBinaryTree(root -> left) + heightofBinaryTree(root -> right) + 1;

    int ans = max(op1,max(op2, op3));
    return ans;
}

//T.C = O(n);
//S.C = O(height of tree);
pair<int, int> getDiameterFast(node* root) {
        if(root == NULL) {
            pair<int, int> p = make_pair(0,0);
            return p;
        }
        
        pair<int, int> leftans = getDiameterFast(root -> left);
        pair<int, int> Rightans = getDiameterFast(root -> right);
        
        int op1 = leftans.first;
        int op2 = Rightans.first;
        int op3 = leftans.second + Rightans.second+1 ;
        
        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(leftans.second, Rightans.second) + 1;
        return ans;
    }

int diameter1(node* root) {
    return getDiameterFast(root).first;
}
int main(){
    node* root = NULL;
    //root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //levelordertraversal

    
    buildtreeByLevelOrder(root);
    int p=heightofBinaryTree(root);
    cout<<"Height of Binary Tree : "<<p<<endl;

    int p = diameter(root);
    cout<<"Diameter of Tree is : "<<p<< endl;

    
    int p = diameter1(root);
    cout<<"Diameter of Tree is : "<<p<<endl;

}