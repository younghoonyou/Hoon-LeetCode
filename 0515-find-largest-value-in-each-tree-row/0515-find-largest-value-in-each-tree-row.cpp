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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int maxs = INT_MIN;
            int size = q.size();
            for(int i = size;i !=0;i--){
                TreeNode *front = q.front();
                q.pop();
                maxs = max(maxs, front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ret.push_back(maxs);
        }
        return ret;
    }
};