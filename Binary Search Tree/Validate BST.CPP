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
// take input values in levelwise

node* insertAtBST(node* root, int data) {
    if(root == NULL) {
        root = new node(data);
        return root;
    }
    
    if(data >  root -> data) {
        // cout<<"Enter the data at left of : "<<endl;
        root -> right = insertAtBST(root -> right, data);
    }
    else{
        // cout<<"Enter the data at right of : "<<endl;
        root -> left = insertAtBST(root -> left, data);
    }
    return root;
}
void buildtree(node* &root) {
    int data;
    cout<<"Enter the root node : "<<endl;
    cin>> data;

    while(data!=-1) {
        root = insertAtBST(root, data);
        cin>>data;
    }
    

}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);

    //For display Level order in proper format
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        if(temp ==NULL) {//purana level complete traverse is done
            cout<<endl;
            //queue still have some child nodes
            //We Used Here a Separator
            //1 -1 3 5 -1 7 11 
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else{
            cout<<temp -> data <<" ";
            if(temp -> left) {
                q.push(temp ->left);
            }
            if(temp -> right) {
                q.push(temp ->right);
            }
        }
    }
}
bool checkBST(node* root, int min, int max)
{
    if(root == NULL) {
        return true;
    }
    if(root -> data > min && root -> data < max) {
        bool left = checkBST(root, min, root ->data);
        bool right = checkBST(root, root-> data, max);
        bool check = (root -> data > min && root -> data < max);
        return left && right && check;
    }
    else{
        return false;
    }        

} 
bool isBST(node* root) {
    return checkBST(root, INT8_MIN, INT8_MAX);
}
int main() {
    node* root = NULL; 
    buildtree(root);
    levelOrderTraversal(root);

    if(isBST(root)) {
        cout<<"Valid BST : "<<endl;
    }
    else{
        cout<<"Not a Valid"<<endl;
    }
}