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
    in.push_back(root -> data);
    inorder(root -> right, in);
}

bool isSum(node* root) {
    vector<int> ans;
    inorder(root, ans);

    int i = 0;
    int j = ans.size()-1;
    int target;
    cout<<"Enter the Sum to find in BST : "<<endl;
    cin>> target;
    while(i<j) {
        int sum = ans[i] + ans[j];
        if(sum == target) {
            return true;
        }

        else if(sum < target){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}
int main() {
    node* root = NULL;
    node* ans = takeinput(root);
    levelorderTraversal(ans);

    if(isSum(root)){
        cout<<"Pair is Found"<<endl;
    }
    

}