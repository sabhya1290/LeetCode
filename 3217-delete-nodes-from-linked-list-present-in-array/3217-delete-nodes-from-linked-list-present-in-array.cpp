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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        unordered_set<int>numSet(nums.begin(),nums.end());
        ListNode*curr=dummy;
        while(curr->next!=NULL){
            if(numSet.count(curr->next->val)){
                curr->next=curr->next->next;
            }
            else{
                curr=curr->next;
            }
        }
    return dummy->next;    
    }
};