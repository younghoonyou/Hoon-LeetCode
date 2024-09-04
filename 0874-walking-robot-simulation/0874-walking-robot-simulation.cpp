class Solution {
private:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
public:    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int direction = 0;
        int furthest = 0;
        set<pair<int, int>> obs;
        for(auto obstacle : obstacles){
            obs.insert({obstacle[0], obstacle[1]});
        }
        
        pair<int,int> position = {0, 0};
        
        for(int &command : commands){
            if(command == -1){
                direction++;
                direction %= 4;
                continue;
            }
            else if(command == -2){
                direction--;
                if(direction < 0) direction += 4;
                continue;
            }
            while (command-- > 0 && !obs.contains({position.first + dx[direction], position.second + dy[direction]})) {
                position.first += dx[direction];
                position.second += dy[direction];
            }
            furthest = max(furthest, position.first*position.first + position.second*position.second);
        }
        return furthest;
    }
};