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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if(head == NULL){
        //     return head;
        // }
        // if(head->next == nullptr){
        //     if(n == 1) return NULL;
        // }
        // int cnt = 0;
        // ListNode* temp = head;
        // while(temp){
        //     cnt++;
        //     temp = temp -> next;
        // }
        // int k = cnt - n;
        // int c = 0;
        // temp = head;
        // while(temp){
        //     c++;
        //     if(c == k){
        //         ListNode* del = temp -> next;
        //         temp ->next = temp->next->next;
        //         delete del;
        //         return head;
        //     }
        //     temp = temp->next;
        // }
        // return head;

        ListNode *ptr = head, *temp = head;
        for (int i = 0; i < n; i++) ptr = ptr->next;
        
        if (!ptr) return head->next;
        
        while (ptr->next) {
            ptr = ptr->next;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;

    }
};