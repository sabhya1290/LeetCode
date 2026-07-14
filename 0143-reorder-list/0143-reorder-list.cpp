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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }
        ListNode* fast = head, *slow = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow -> next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;

        while(second != nullptr){

            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }
        second = prev;
        ListNode* front = head;
        while(second != nullptr){
            ListNode* temp = front->next;
            ListNode* t = second->next;
            front->next = second;
            second->next = temp;
            front = temp;
            second = t;
        }
    }
};