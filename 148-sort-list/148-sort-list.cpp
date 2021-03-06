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
        if(head==NULL)
            return head;
        vector<int> v;
        ListNode *ptr = head;
        while(ptr){
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        sort(v.begin(), v.end());
        head->val = v[0];
        ptr = head->next;
        int n = v.size();
        for(int i=1;i<n;++i){
            ptr->val = v[i];
            ptr = ptr->next;
        }
        return head;
    }
};