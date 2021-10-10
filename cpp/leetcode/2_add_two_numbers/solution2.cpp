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
       
        int sum = 0;
        ListNode* result = NULL;
        ListNode** p = &result;
        
        while(l1 != NULL || l2 != NULL || sum > 0){
            if(NULL != l1){
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(NULL != l2){
                sum += l2->val;
                l2 = l2->next;
            }
            
            (*p) = new ListNode(sum%10);
            sum /= 10;
            p = &((*p)->next);
        }
        
        return result;
    }
};
