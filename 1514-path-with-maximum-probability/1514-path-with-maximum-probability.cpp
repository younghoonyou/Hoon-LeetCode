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
            int top = q.front(); q.pop();
            for(auto v : vertex[top]){
                int next_node = v.first;
                double weight = v.second;
                if(Probability[top]*weight > Probability[next_node]){
                    Probability[next_node] = Probability[top]*weight;
                    q.push(next_node);
                }
            }
        }
        return Probability[end_node];
    }
};