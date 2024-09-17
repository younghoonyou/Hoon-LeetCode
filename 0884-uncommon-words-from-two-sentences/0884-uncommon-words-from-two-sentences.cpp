class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        map<string, int> m;
        istringstream ss(s1 + " " + s2);
        string buffer;
        while(getline(ss, buffer, ' ')){
            m[buffer]++;
        }
        for(auto it:m){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};