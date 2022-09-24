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
        return NULL;
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
    cin>> data;
    while(data!=-1) {
        root=insertAtBST(root, data);
        cin>>data;
    }
    return root;
}


void inorder(node* root, vector<int>& ans) {
    if(root == NULL) {
        return;
    }

    inorder(root -> left, ans);
    ans.push_back(root -> data);
    inorder(root -> right, ans);
}

vector<int> merge(vector<int> &a, vector<int> &b) {
    vector<int> ans(a.size()+b.size());
    
    int i=0;
    int j=0;
    int k=0;
    while(i < a.size() && j < b.size()) {
        if(a[i] < b[j]) {
            ans[k++] = a[i++];
        }
        else{
            ans[k++] = b[j++];
        }
    }
    while(i<a.size()) {
        ans[k++] = a[i++];
    }
    while(j<b.size()) {
        ans[k++] = b[j++];
    }
    return ans;
}
node* BST(int i,int j, vector<int> &ans) {
    if(i>j) {
        return NULL;
    }

    int mid = (i+j)/2;
    node* curr = new node(ans[mid]);
    curr -> left = BST(i, mid-1, ans);
    curr -> right = BST(mid+1, j, ans);

    return curr;
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

int main() {

    node* root1 = NULL;
    node* root2 = NULL;
    node* ans1 = takeinput(root1);
    cout<<"FirstBST : "<<endl;
    levelOrderTraversal(ans1);
    node* ans2 = takeinput(root2);
    cout<<"SecondBST : "<<endl;
    levelOrderTraversal(ans2);


     //step1
    vector<int> tmp;
    vector<int> tmp1;
    inorder(ans1, tmp);
    inorder(ans2, tmp1);

    // step2
    vector<int> mergeArray = merge(tmp, tmp1);

    // step3
    node* BSTTree = BST(0, mergeArray.size()-1, mergeArray);

    cout<<"Merged BST : " <<endl;
    levelOrderTraversal(BSTTree);




}
