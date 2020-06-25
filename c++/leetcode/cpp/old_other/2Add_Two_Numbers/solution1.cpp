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
       
        ListNode* result = NULL;
        ListNode* p;
        int temp = 0;
        
        while((NULL != l1->next) && (NULL != l2->next)){//保证两个的下一个都没有结束
            temp = l1->val + l2->val;
            if(temp>=10){//这个就是要进位
                l1->next->val += 1; 
                temp -= 10;
            }
            
            if(NULL == result){//第一次
                result = new ListNode(temp);
                p = result;
            }
            else{
                result->next = new ListNode(temp);
                result = result->next;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        temp = l1->val + l2->val;
        if(temp>=10){
            if(NULL == result){
                result = new ListNode(temp - 10);
                p = result;
            }
            else{
                result->next = new ListNode(temp - 10);
                result = result->next;
            }
        }
        else{
            if(NULL == result){
                result = new ListNode(temp);
                p = result;
            }
            else{
                result->next = new ListNode(temp);
                result = result->next;
            }
        }
        
        l1 = l1->next;
        l2 = l2->next;
        
        //处理有结束的
        //需要确定是谁结束
        if(NULL == l1 && NULL == l2){
            
            if(temp>=10){
                result->next = new ListNode(1);
            }
            return p;
        }
        else if(NULL == l1){//l1结束
            
            if(temp>=10){
                l2->val += 1;
            }
            
            while(NULL != l2){
                if(l2->val >= 10){
                    result->next = new ListNode(l2->val - 10);
                    result = result->next;
                    if(NULL == l2->next){
                       result->next = new  ListNode(1);
                        return p;
                    }
                    else{
                        l2->next->val += 1;
                    }
                    l2 = l2->next;
                }
                else{
                    result->next = new ListNode(l2->val);
                    result = result->next;
                    l2 = l2->next;  
                }
            }  
            return p;
        }
        else if(NULL == l2){
           if(temp>=10){
                l1->val += 1;
            }
            
            while(NULL != l1){
                if(l1->val >= 10){
                    result->next = new ListNode(l1->val - 10);
                    result = result->next;
                    if(NULL == l1->next){
                        result->next = new  ListNode(1);
                        return p;
                    }
                    else{
                        l1->next->val += 1;
                    }
                    l1 = l1->next;
                }
                else{
                    result->next = new ListNode(l1->val);
                    result = result->next;
                    l1 = l1->next;  
                }
            }  
            return p;  
        }
        else{
            
            return p;
        }

        return p;
        
    }
};
