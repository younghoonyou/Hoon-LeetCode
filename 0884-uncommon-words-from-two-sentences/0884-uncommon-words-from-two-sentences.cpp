class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        map<string, int> m;
        istringstream ss1(s1);
        string buffer;
        while(getline(ss1, buffer, ' ')){
            m[buffer]++;
        }
        istringstream ss2(s2);
        while(getline(ss2, buffer, ' ')){
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