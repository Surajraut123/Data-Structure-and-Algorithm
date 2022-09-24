#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    int data;
    Solution* next;
    Solution(int data) {
        this -> data = data;
        this -> next = NULL;
    }
    Solution(){}
    
    void multiply(Solution* &head, int d) {
        Solution* curr = head;
        Solution* check = NULL;
        int carry = 0;
        while(curr!=NULL) {
            int digit = curr -> data * d + carry;
            int value = digit%10;
            carry = digit/10;
            curr -> data = value;
            check = curr;
            curr = curr -> next;
        }
        
        while(carry!=0) {
            Solution* newNode = new Solution((carry%10));
            carry = carry/10;
            newNode -> next = check;
        }
    }
    
    Solution* reverse(Solution* tmp) {
        Solution* prev = NULL;
        Solution* curr = NULL;
        
        while(tmp != NULL) {
            curr = tmp -> next;
            tmp -> next = prev;
            prev = tmp;
            tmp = curr;
        }
        
        return prev;
    }
    
    vector<int> factorial(int N){
        
        vector<int> ans;
        Solution* node1 = new Solution(1);
        for(int i=1;i<=N;i++) {
            multiply(node1, i);
        }
        node1 = reverse(node1);
        while(node1!=NULL) {
            ans.push_back(node1 -> data);
            node1 = node1 -> next;
        }
        
        return ans;
        
        
    }
};


int main() {
    int n;
    cout<<"Enter the Number : "<<endl;
    cin>>n;

    Solution obj;

    vector<int> ans = obj.factorial(n);
}