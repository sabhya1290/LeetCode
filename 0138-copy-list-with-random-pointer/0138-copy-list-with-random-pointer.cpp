/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
void nextt(Node* temp){
    while(temp){
    Node* newn = new Node(temp->val);
    newn->next = temp->next;
    temp->next = newn;
    temp = newn->next;
    }
}
void ran(Node* temp){
    while(temp){
    if(temp->random) temp->next->random = temp->random->next;
    else temp->next->random = temp->random;
    temp = temp->next->next;
    }
}
Node* dele(Node* temp){
    Node* res = new Node(-1);
    Node* dum = res;
    while(temp){
    res->next = temp->next;
    temp->next = temp->next->next;
    temp = temp->next;
    res = res->next;
    }
    return dum->next;
}
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        nextt(head);
        ran(head);
        return dele(head);
    }
};