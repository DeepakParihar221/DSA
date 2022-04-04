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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* p=head;
        int ctr=0;
        while(p!=NULL)
        {
            ctr++;
            p=p->next;
        }
        ListNode* q=head;
        ListNode* r;
        ListNode* s;
       
        int count=0;
        while(q!=NULL)
        {
            count++;
            if(count==k)
                r=q;
            if(count == (ctr-k+1))
                s=q;
            q=q->next;
        }
        swap(r->val, s->val);
        
        return head;
    }
};