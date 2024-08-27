class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int, double>> vertex[n];
        vector<double> Probability(n);
        int size = edges.size();
        
        for(int i=0;i<size;++i){
            vertex[edges[i][0]].push_back({edges[i][1], succProb[i]});
            vertex[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        queue<int> q;
        Probability[start_node] = 1;
        q.push(start_node);
        
        while(!q.empty()){
            int p = q.front(); q.pop();
            for(auto x : vertex[p]){
                int i = x.first;
                double j = x.second;
                if(Probability[p]*j > Probability[i]){
                    Probability[i] = Probability[p]*j;
                    q.push(i);
                }
            }
        }
        return Probability[end_node];
    }
};