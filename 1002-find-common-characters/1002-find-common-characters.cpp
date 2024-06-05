class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        std::vector<int> common(26,0);
        int size = words.size();
        
        for(char &ch:words[0]){
            common[ch -'a']++;
        }
        
        for(int i=1;i<size;++i){
            std::vector<int> current(26, 0);
            for(char &ch:words[i]) current[ch-'a']++;
            for(int j=0;j<26;++j) common[j] = min(common[j], current[j]);
        }
        
        vector<string> ret;
        for(int k=0;k<26;++k){
            for(int cnt = 0;cnt<common[k];cnt++) ret.push_back(std::string(1, k + 'a'));
        }
        return ret;
    }
};