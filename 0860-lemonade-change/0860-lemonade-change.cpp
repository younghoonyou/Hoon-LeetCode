class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five, ten;
        five = ten = 0;
        for(int &charge : bills){
            if(charge == 5) five++; // $5
            else if(charge == 10) ten++, five--; // $10
            else if(ten > 0) ten--,five--; // $20
            else five-=3;
            if(five < 0) return false;
        }
        return true;
    }
};