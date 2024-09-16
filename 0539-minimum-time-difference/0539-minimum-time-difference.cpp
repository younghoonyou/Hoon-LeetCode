class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int size = timePoints.size();
        int ans = INT_MAX;
        vector<int> times;
        for(string &time : timePoints){
            times.push_back(stoi(time.substr(0,2))*60 + stoi(time.substr(3,2)));
        }
        sort(times.begin(), times.end());
        times.push_back(times[0] + 24*60);
        for(int i=1;i<size + 1;++i){
            ans = min(ans, times[i] - times[i-1]);
        }
        return ans;
    }
};