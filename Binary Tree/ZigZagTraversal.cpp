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


node* buildTree(node* root) {
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data==-1) {
        return NULL;
    }

    cout<<"Enter the data in Left "<<data<<endl;
    root -> left = buildTree(root->left);

    cout<<"Enter the data in Right "<<data<<endl;
    root -> right = buildTree(root -> right);

    return root;

}

vector<int> zigzagTraversal(node* root) {
    vector<int> result;
    if(root == NULL) {
        return result;
    }
    queue<node*> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()) {
        int size = q.size();
        vector<int> ans(size);
        int index;
        for(int i=0; i<size; i++) {
            node* tmp = q.front();
            q.pop();
            if(leftToRight){
                index = i;
            }
            else{
                index = size - i - 1;
            }

            ans[index] = tmp -> data;
            if(tmp -> left) {
                q.push(tmp -> left);
            }

            if(tmp -> right) {
                q.push(tmp -> right);
            }
            leftToRight = ! leftToRight;
            for(auto i : ans) {
                result.push_back(i);
            }
        }
    }
    return result;

}

int main(){
    node* root = NULL;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    
    vector<int> Result = zigzagTraversal(root);
    for(int i=0;i<Result.size();i++) {
        cout<<Result[i] << " ";
    }
    
    
}