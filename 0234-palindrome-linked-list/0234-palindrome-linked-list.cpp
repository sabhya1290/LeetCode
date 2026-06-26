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
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = head;
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        while(prev){
            if(prev->val!=head->val){
                return false;
            }
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};