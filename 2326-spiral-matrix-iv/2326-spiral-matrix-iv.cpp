/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    bool checkValidation(vector<vector<int>>& ret, int dir, pair<int,int> &position, int m, int n){
        switch(dir){
            case 0:
                if(position.second + dy[dir] >= n || ret[position.first][position.second + dy[dir]] != -1) return false;
                break;
            case 1:
                if(position.first + dx[dir] >= m || ret[position.first + dx[dir]][position.second] != -1) return false;
                break;
            case 2:
                if(position.second + dy[dir] < 0 || ret[position.first][position.second + dy[dir]] != -1) return false;
                break;
            case 3:
                if(position.first + dx[dir] < 0 || ret[position.first + dx[dir]][position.second] != -1) return false;
                break;
        }
        return true;
    }
    
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ret(m, vector<int>(n,-1));
        int dir = 0;
        pair<int,int> position(0, 0);
        while(head){
            int x = position.first;
            int y = position.second;
            ret[x][y] = head->val;
            if(!checkValidation(ret, dir, position, m, n)){
                dir++;
                dir %= 4;
            }
            position.first += dx[dir];
            position.second += dy[dir];
            head = head->next;
        }
        return ret;
    }
};