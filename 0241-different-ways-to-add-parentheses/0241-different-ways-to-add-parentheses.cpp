class Solution {
public:
    static int helperCompute(int num1, int num2, char op){
        switch(op){
            case '+':
                return num1 + num2;
            case '*':
                return num1 * num2;
            case '-':
                return num1 - num2;
        }
        return -1;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        bool isNumber = true;
        
        for(int i=0;i<expression.size();++i){
            if(!isdigit(expression[i])){
                isNumber = false;
                vector<int> leftCompute = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightCompute = diffWaysToCompute(expression.substr(i + 1));
                for(int left : leftCompute){
                    for(int right : rightCompute){
                        result.push_back(helperCompute(left, right, expression[i]));
                    }
                }
            }
        }

        if(isNumber) result.push_back(stoi(expression));

        return result;
    }
};