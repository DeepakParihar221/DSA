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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ptr = head, *temp = head;
        while(ptr!=NULL){
            int sum = 0;
            ptr = ptr->next;
            while((ptr!=NULL) && ptr->val!=0){
                sum += ptr->val;
                ptr = ptr->next;
            }
            if(sum>0){
                ListNode* med = new ListNode(sum);
                temp->next = med;
                med->next = ptr->next;
                temp = temp->next;
            }
            // else if(sum==0){
            //     head = ptr
            // }
        }
        return head->next;
    }
};