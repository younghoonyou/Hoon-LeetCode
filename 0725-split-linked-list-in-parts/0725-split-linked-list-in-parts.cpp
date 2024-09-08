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
        vector<ListNode*> ret(k, nullptr);
        ListNode *curr = head;
        int len = 0;
        while(curr){
            len++;
            curr = curr->next;
        }
        int n = len / k;
        int r = len % k;
        curr = head;
        ListNode *prev = nullptr;
        for(int i=0;curr != nullptr && i<k;++i,r--){
            ret[i] = curr;
            for(int j=0;j < n+(r > 0 ? 1 : 0);++j){
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
        }
        return ret;
    }
};