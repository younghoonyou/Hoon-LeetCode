class Solution {
private:
    map<int,string> num_map {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"}
  };
    
public:
    string num_string(int num){
        if(num >= 1000000000)  return num_string(num / 1000000000) + "Billion " + num_string(num - 1000000000 * (num / 1000000000));
        else if(num >= 1000000) return num_string(num / 1000000) + "Million " + num_string(num - 1000000 * (num / 1000000));
        else if(num >= 1000)    return num_string(num / 1000) + "Thousand " + num_string(num - 1000 * (num / 1000));
        else if(num >= 100)     return num_string(num / 100) + "Hundred " + num_string(num - 100 * (num / 100));
        else if(num >= 20)      return num_map[(num / 10) * 10] + string(" ") + num_string(num - 10 * (num / 10));
        else if(num >= 1)       return num_map[num] + string(" ");
        else return "";
    }
    
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string ret = num_string(num);
        ret.pop_back();
        return ret;
    }
};