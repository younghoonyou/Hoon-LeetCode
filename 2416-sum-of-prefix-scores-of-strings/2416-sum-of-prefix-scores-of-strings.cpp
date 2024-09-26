class TrieNode{
public:
    map<char, TrieNode*> children;
    int val = 0;
};

class Solution {
private:
    TrieNode* manager = nullptr;
public:
    void insertNode(string word){
        TrieNode *curr = manager;
        for(char &ch:word){
            if(!curr->children[ch]) curr->children[ch] = new TrieNode();
            curr = curr->children[ch];
            curr->val++;
        }
    }
    
    int getScore(string word){
        TrieNode *curr = manager;
        int total = 0;
        for(char &ch:word){
            curr = curr->children[ch];
            total += curr->val;
        }
        return total;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        manager = new TrieNode();
        for(string &word:words){
            insertNode(word);
        }
        vector<int> ans;
        for(string &word:words){
            ans.push_back(getScore(word));
        }
        return ans;
    }
};