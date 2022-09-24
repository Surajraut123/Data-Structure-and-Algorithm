
//Definition for singly-linked list.

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    
private:
    ListNode* reverseLL(ListNode* &tmp, int left, int right) {
        ListNode* curr = tmp;
        ListNode* prev = 0;
        ListNode* forward = tmp;
        
        int position = (right - left) + 1;
        int cnt=1;
        while(cnt < position) {
            forward = curr -> next;
            curr -> next = prev;
            prev= curr;
            curr = forward;
            cnt++;
        }
        forward = curr -> next;
        curr -> next = prev;
        tmp -> next = forward;
        return curr;
        
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 1;
        ListNode* tmp = head;
        ListNode* curr = 0;
        
        if(left == 1 && right == 1) {
            return head;
        }
        while(cnt < left) {
            curr = tmp;
            tmp = tmp -> next;
            cnt++;
        }
        if(left == 1) {
            return reverseLL(tmp, left, right);
        }
        else{
            curr -> next = reverseLL(tmp, left, right);
        }
        return head;
        
    }
};