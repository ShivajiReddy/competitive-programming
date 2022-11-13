/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        stack<int> s;
        
        while(slow != NULL ) {
            s.push(slow->val);
            slow = slow->next;
        }
        
        //Now slow points to mid
        slow = head;
        while(slow != NULL) {
            if(s.top() != slow->val) 
                return false;
            s.pop();
            slow = slow->next;
        }
        
        return true;
    }
};