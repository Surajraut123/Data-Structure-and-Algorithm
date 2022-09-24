
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
    
    ListNode* merge(ListNode* left, ListNode* right) {
        if(left == nullptr) {
            return right;
        }
        if(right == nullptr) {
            return left;
        }
        ListNode* curr = new ListNode(-1);
        ListNode* tmp = curr;
        
        while(left != nullptr && right != nullptr) {
            if(left -> val < right -> val) {
                tmp -> next = left;
                tmp = left;
                left = left -> next;
            }
            else{
                tmp -> next = right;
                tmp = right;
                right = right -> next;
            }
        }
        
        while(left != nullptr) {
            tmp -> next = left;
            tmp = left;
            left = left -> next;
        }
        while(right != nullptr) {
            tmp -> next = right;
            tmp = right;
            right = right -> next;
        }
        curr= curr -> next;
        return curr;
    }
    
    
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) {
            return head;
        }
        ListNode * mid = findMid(head);
        
        ListNode* left = head;
        ListNode* right = mid -> next;
        mid -> next = nullptr;
        
        left = sortList(left);
        right = sortList(right);
        
        ListNode* result = merge(left, right);
        return result;
    }
};