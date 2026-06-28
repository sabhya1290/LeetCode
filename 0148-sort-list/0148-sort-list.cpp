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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* L = head;
        ListNode* mid = getmid(head);
        ListNode* R = mid->next;
        mid->next = NULL;
        L = sortList(L);
        R = sortList(R);
        return merge(L,R);
    }
private:
    ListNode* getmid(ListNode *head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode *L, ListNode *R){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (L && R) {
            if (L->val < R->val) {
                tail->next = L;
                L = L->next;
            } else {
                tail->next = R;
                R = R->next;
            }
            tail = tail->next;
        }
        
        // Append any remaining nodes from either list
        tail->next = L ? L : R;
        
        return dummy.next;
    }
    };