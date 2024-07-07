class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ret = numBottles;
        int start = numBottles;
        while(start / numExchange)
        {
            ret += start / numExchange;
            start = start / numExchange + start % numExchange;
        }
        return ret;
    }
};