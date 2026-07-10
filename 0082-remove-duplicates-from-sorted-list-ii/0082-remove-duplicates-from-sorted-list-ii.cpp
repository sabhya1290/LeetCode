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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;

        ListNode* dummy = new ListNode(0); // dummy node with value 0
        dummy->next = head;

        ListNode* prev = dummy; // points to the last node known to be unique.
        ListNode* curr = head; // traverses the list

        while(curr != NULL) {
            if(curr->next != NULL && curr->val == curr->next->val) {
                int duplicate = curr->val;

                // skip all duplicates
                while(curr != NULL && curr->val == duplicate) {
                    curr = curr->next;
                }

                prev->next = curr;
            }

            else { // update both prev and curr pointers
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};