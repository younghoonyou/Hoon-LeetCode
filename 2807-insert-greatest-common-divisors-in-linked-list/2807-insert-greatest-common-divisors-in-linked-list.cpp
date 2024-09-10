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
    int divisor(int a, int b){
        if(b == 0) return a;
        return divisor(b, a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *curr = head;
        while(curr->next){
            int div = divisor(curr->val, curr->next->val);
            ListNode *node = new ListNode(div);
            node->next = curr->next;
            curr->next = node;
            curr = node->next;
        }
        return head;
    }
};