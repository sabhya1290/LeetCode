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
        // stack<int> st;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        int carry = 0;
        int sum = 0;
        while((t1 || t2) || carry != 0){
            if(t1 == NULL && t2 == NULL){
                temp->next =new ListNode((carry));
                break;
            }
            if(t1 == NULL){
                sum = t2->val + carry;   
                t2 = t2->next;
            }
            else if(t2 == NULL){
                sum = t1->val + carry;
                t1 = t1->next;
            }
            else{
                sum = t1 ->val + t2->val + carry;
                t1 = t1->next;
                t2 = t2->next;
            }
            carry = sum / 10;
            temp->next =new ListNode((sum % 10));
            temp = temp->next;
        }
        return ans->next;
    }
};