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
    void findNum(unordered_set<int>& st, ListNode **node){
        while(st.count((*node)->val)){
            if((*node)){
                (*node) = (*node)->next;
            }
        }
        
        ListNode *prev, *curr;
        prev = curr = (*node);
        
        while(curr){
            if(st.count(curr->val)){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        findNum(st, &head);
        return head;
    }
};