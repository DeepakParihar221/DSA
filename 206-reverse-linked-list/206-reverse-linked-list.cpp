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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *prev=head, *curr=head->next, *next=curr;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            //update
            prev = curr;
            curr = next;
            
        }
        head->next = NULL;
        head = prev;
        return head;
    }
};