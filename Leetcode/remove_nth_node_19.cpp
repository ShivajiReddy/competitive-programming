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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto res = head;
        int i = 0;
        auto root = head;
        while(root != NULL) {
            i++;
            root = root->next;
        }
        if(i==n) 
            return head->next;
        int m = i - n;
        i = 1;
        while(head != NULL && i < m) {
            i++;
            head = head->next;
        }
        head->next = head->next->next;
        
        return res;
    }
};