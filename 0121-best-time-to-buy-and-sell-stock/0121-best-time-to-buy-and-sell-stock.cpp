class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int profit = 0;
        for(int &p : prices){
            if(p < minprice) minprice = p;
            else profit = max(profit, p - minprice);
        }
        return profit;
    }
};