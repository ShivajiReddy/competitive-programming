https://leetcode.com/problems/reverse-linked-list-ii/
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
 
class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
       
        ListNode* current = head;
        ListNode* previous;
        
        
        for(int i = 1; i < left; i++) 
        {
            previous = current;
            current = current->next;
        }
        
        ListNode* next = NULL; 
        ListNode* lastPrev = previous;
        ListNode* lastCur = current;
        
        while(right-left+1) 
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
            right--;
        }
        
        if(lastPrev == NULL)
            head = previous;
        else
            lastPrev->next = previous;
            
        
        lastCur->next = current;
        
        return head;
        
    }
};