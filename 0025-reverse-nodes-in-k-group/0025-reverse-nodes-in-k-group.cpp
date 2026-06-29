/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        
        ListNode dummy(0);
        dummy.next = head;

        
        ListNode* beforeGroup = &dummy;
        ListNode* groupStart = dummy.next;
        ListNode* groupEnd = dummy.next;

        while(groupStart){
            int actualLen = 0;
            
            while(groupEnd && actualLen < k){
                actualLen++;
                if(actualLen == k) break;
                groupEnd = groupEnd->next;
            }
            
            if(actualLen < k) break;
            
            ListNode* nextStart = groupEnd->next;
            
            ListNode* curr = groupStart;
            ListNode* prev = nextStart; 
            
            while(actualLen--){
                ListNode* getNext = curr->next;
                curr->next = prev;
                prev = curr;
                curr = getNext;
            }
            
            beforeGroup->next = prev;
            
            beforeGroup = groupStart;
            groupStart = nextStart;
            groupEnd = groupStart;
        }
        
        return dummy.next;
    }
};