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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* ptr1 = head, *ptr2 = head->next, *nextsublist;
        head = ptr2;
        while(ptr1 && ptr2){
            nextsublist = ptr2->next;
            
            if(nextsublist != NULL && nextsublist->next!=NULL){
                ptr2->next = ptr1;
                ptr1->next = nextsublist->next;
                ptr1 = nextsublist;
                ptr2 = nextsublist->next;
            }
            else{
                ptr1->next = nextsublist;
                ptr2->next = ptr1;
                ptr1 = NULL;
                ptr2 = NULL;
            }
        }
        
        return head;
    }
};