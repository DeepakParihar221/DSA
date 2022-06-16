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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* ptr = head;
        vector<ListNode*> ans;
        while(ptr!=NULL){
            n++;
            ptr = ptr->next;
        }
        int extra = n%k;
        int size = n/k;
        ptr = head;
        
        while(head!=NULL){
            int l = size;
            if(extra>0)
            while(extra>0 && l>0 && ptr!=NULL){
                ptr = ptr->next;
                l--;
            }
            else{
                l--;
                while(l>0 && ptr!=NULL){
                    ptr = ptr->next;
                    l--;
                }
            }
            
            extra--;
            ListNode* temp = ptr;
            // if(ptr->next!=NULL) temp = ptr->next;
            ptr = ptr->next;
            // ptr->next = NULL;
            temp->next = NULL;
            ans.push_back(head);
            head = ptr;
            
            // if(head==NULL){
            //     break;
            // }
            
        }
        while(ans.size()<k){
            ans.push_back(NULL);
        }
        return ans;
    }
};