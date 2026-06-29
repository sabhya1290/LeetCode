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
        ListNode* ans = new ListNode(0, NULL);
        ListNode* temp = ans; 
        int carryforward = 0;

        while(l1 != NULL || l2 != NULL){
            if(l1 != NULL){
                temp->val += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                temp->val += l2->val;
                l2 = l2->next;
            }
            carryforward = (int) temp->val/10;
            temp->val -= (carryforward*10);
            
            if((l1 != NULL || l2 != NULL) || carryforward != 0) temp->next = new ListNode(carryforward, NULL);
            temp = temp->next;
        }
        return ans;
    }
};