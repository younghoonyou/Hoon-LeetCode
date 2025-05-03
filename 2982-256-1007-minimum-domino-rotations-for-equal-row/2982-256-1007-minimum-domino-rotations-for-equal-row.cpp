class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        std::map<int, int> m;
        int standard = -1;
        int len = tops.size();
        for(int i=0;i < len;++i){
            if(tops[i] == bottoms[i]){
                standard = tops[i];
                m[tops[i]]++;
                continue;
            }
            else{
                m[tops[i]]++;
                m[bottoms[i]]++;
            }
        }

        if(standard != -1){
            int top_cnt = 0;
            int bot_cnt = 0;

            for(int i=0;i<len;++i){
                if(tops[i] != standard && bottoms[i] != standard) return -1;
                if(tops[i] == bottoms[i] && tops[i] == standard) continue;
                if(tops[i] == standard) bot_cnt++;
                if(bottoms[i] == standard) top_cnt++;
            }
            return min(top_cnt, bot_cnt);
        }
        else{
            for(auto it:m){
                if(it.second == len){
                    standard = it.first;
                    int top_cnt = 0;
                    int bot_cnt = 0;

                    for(int i=0;i<len;++i){
                        if(tops[i] != standard && bottoms[i] != standard) return -1;
                        if(tops[i] == bottoms[i] && tops[i] == standard) continue;
                        if(tops[i] == standard) bot_cnt++;
                        if(bottoms[i] == standard) top_cnt++;
                    }
                    return min(top_cnt, bot_cnt);
                }
            }
        }
        return -1;
    }
};