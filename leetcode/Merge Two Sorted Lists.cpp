/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4



 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * n;
        ListNode * h = NULL;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        while(l1&&l2){
            
            int min;
            if(l1->val<=l2->val){
                min = l1->val;
                l1 = l1->next;
            }else{
                min = l2->val;
                l2 = l2->next;
            }
            
            if(!h){
                h = new ListNode(min);
                n = h;
            }else{
                n->next = new ListNode(min);
                n = n->next;
            }

        }
        while(l1){
            n->next = new ListNode(l1->val);
            n = n->next;
            l1 = l1->next;
        }
        while(l2){
            n->next = new ListNode(l2->val);
            n = n->next;
            l2 = l2->next;
        }
        return h;
        
    }
};