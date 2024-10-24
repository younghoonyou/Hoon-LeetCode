/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 && root2 || root1 && !root2 || root1->val != root2->val ) return false;
        bool left_left = flipEquiv(root1->left, root2->left);
        bool left_right = flipEquiv(root1->left, root2->right);
        bool right_left = flipEquiv(root1->right, root2->left);
        bool right_right = flipEquiv(root1->right, root2->right);
        return left_right && right_left || left_left && right_right;
    }
};