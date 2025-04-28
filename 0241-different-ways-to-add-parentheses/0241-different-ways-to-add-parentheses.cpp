class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        for(int i=0; i<expression.length(); i++){
            char ch = expression[i];
            if(ch=='-' || ch=='+' || ch=='*'){
                vector<int> vect1 = diffWaysToCompute(expression.substr(0,i));
                vector<int> vect2 = diffWaysToCompute(expression.substr(i+1));
                for(int n1 : vect1){
                    for(int n2 : vect2){
                        if(ch=='-'){
                            result.push_back(n1-n2);
                        } else if(ch=='+'){
                            result.push_back(n1+n2);
                        } else {
                            result.push_back(n1*n2);
                        }
                    }
                }
            }
        }
        if(result.empty()) result.push_back(stoi(expression));
        return result;
    }
};