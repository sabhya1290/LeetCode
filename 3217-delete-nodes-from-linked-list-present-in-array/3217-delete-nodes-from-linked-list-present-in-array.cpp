class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> removeValues(nums.begin(), nums.end());

        while (head && removeValues.count(head->val)) {
            head = head->next;
        }

        ListNode* curr = head;
        while (curr && curr->next) {
            while (curr->next && removeValues.count(curr->next->val)) {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return head;
    }
};