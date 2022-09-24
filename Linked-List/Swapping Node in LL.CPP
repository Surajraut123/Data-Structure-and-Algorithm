
 //Definition for singly-linked list.
 //Here Considered NULL as 0;
 struct ListNode {
     int val;
     ListNode *next;
     
     ListNode() : val(0), next(0) {}
     ListNode(int x){
        this -> val = x;
        this -> next = 0;
     }     
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {

public:
    ListNode* swapNodes(ListNode* head, int k) {
        int count=0;
        ListNode* tmp1=0;
        ListNode* tmp2=0;
        ListNode* curr = head;
        ListNode* prev = head;
        
        while(prev!=0) {
            count++;
            prev = prev -> next;
        }
        if(count==1) {
            return head;
        }
        
        if(count==2) {
            prev = curr -> next;
            curr -> next = prev -> next;
            prev -> next = curr;
            return prev;
        }
        
        // if(count==k) {
        //     tmp1 = curr -> next;
        //     curr -> next = prev -> next;
        //     prev -> next = tmp1;
        //     tmp2 -> next = curr;
        //     return prev;
        // }
        
        
        int s=1;
        prev=head;
        while(s<=k-1) {
            tmp1 = curr;
            curr = curr -> next;
            s++;
        }
        s=1;
        while(s <= count-k) {
            tmp2 = prev;
            prev = prev ->next;
            s++;
        }
        if(k==1 ){
            tmp1 = curr -> next;
            curr -> next = prev -> next;
            prev -> next = tmp1;
            tmp2 -> next = curr;
            return prev;
        }
        else{
            tmp1 -> next = prev;
            tmp1 = tmp1 ->next;
            
            tmp2 -> next = curr;
            tmp2 = tmp2 -> next;
            
            prev = prev -> next;
            curr = curr -> next;
            
            tmp1 -> next = curr;
            tmp2 -> next = prev;
        }
        
        return head;
    }    
};