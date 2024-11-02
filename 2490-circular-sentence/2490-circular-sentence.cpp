class Solution {
public:
    bool isCircularSentence(string sentence) {
        int sz = sentence.size();
        if(sentence[0] != sentence[sz - 1]) return false;
        for(int i = 0; i < sz;++i)
            if(sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) return false;
        return true;
    }
};