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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans;
        ListNode*temp = new ListNode(-1);
        ans = temp ;
        while(l1 != NULL && l2!=NULL){
            ListNode* New_Node = new ListNode((l1->val + l2->val + carry)%10);
            carry =  (l1->val + l2->val + carry)/10;
            l1 = l1->next;
            l2 = l2->next;
            temp->next = New_Node;
            temp = temp->next;
        }
        
        while(l1!= NULL ){
            ListNode* New_Node = new ListNode((l1->val + carry)%10);
            carry =  (l1->val + carry)/10;
            l1 = l1->next;
            temp->next = New_Node;
            temp = temp->next;
        }
        
        while(l2!= NULL ){
           ListNode* New_Node = new ListNode(( l2->val + carry)%10);
            carry =  (l2->val + carry)/10;
            l2 = l2->next;
            temp->next = New_Node;
            temp = temp->next;
        }
        
        if(carry == 1){
            ListNode* New_Node = new ListNode(1);
            temp->next = New_Node;
            temp = temp->next;
        }
        return ans->next;
    }
};