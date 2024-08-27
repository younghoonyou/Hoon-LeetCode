/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int> ret;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node *top = s.top();
            s.pop();
            for(int i=0;i<(top->children).size();++i){
                s.push(top->children[i]);
            }
            ret.push_back(top->val);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};