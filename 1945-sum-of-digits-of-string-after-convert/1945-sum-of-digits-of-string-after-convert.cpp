class Solution {
public:
    
    int getLucky(string s, int k) {
        string strtoint;
        int sum = 0;
        
        for(char &ch : s){
            strtoint += to_string(ch - 'a' + 1);
        }
        
        while(k--){
            sum = 0;            
            for(char &ch : strtoint){
                sum += ch - '0';
            }
            strtoint = to_string(sum);
        }
        
        return sum;
    }
};