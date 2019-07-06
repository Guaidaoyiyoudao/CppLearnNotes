/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.




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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *l;
        ListNode *r;
        ListNode *p;
        ListNode * result = NULL;
        bool af = false;
        
        l = l1;
        r = l2;
        int v1,v2;
        int sum = 0;
        while(l!=NULL||r!=NULL){
            v1 = l?l->val:0;
            v2 = r?r->val:0;
            
            sum = v1 + v2;
            if(af){
                sum += 1;
                af = false;
            }
            if(sum>=10){
                sum -= 10;
                af = true;
            }
            if(!result){
                result = new ListNode(sum);
                p = result;
            }else{
              
                p->next = new ListNode(sum);
                p = p->next;
                
            }
                
            l = l?l->next:NULL;
            r = r?r->next:NULL;        
            
        }
        if(af){
            p->next = new ListNode(1);
        }
        

            
        return result;  
    }
};