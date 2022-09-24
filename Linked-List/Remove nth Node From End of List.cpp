
  //Definition for singly-linked list.
  //Considered NULL as 0

  //LeetCode Question
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==0) {
            return 0;
        }
        
        ListNode* curr = head;
        ListNode* tmp = head;
        int cnt=0;
        while(curr!=0) {
            curr = curr->next;
            cnt++;
        }
        int remove = cnt-n;
        if(remove==0){
            head = head->next;
            return head;
        }
        
        while(--remove) {
            tmp = tmp->next;
        }
        
        curr = tmp->next;
        tmp->next = curr->next;
        curr->next = 0;
        return head;
    }
};