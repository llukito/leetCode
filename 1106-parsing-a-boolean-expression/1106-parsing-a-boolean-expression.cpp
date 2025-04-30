class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> operators;
        stack<char> values;
        for(char ch : expression){
            if(ch == ',')continue;
            if(isOperator(ch)){
                operators.push(ch);
            } else {
                if(ch == ')'){
                    char operat = 'N';
                    if(!operators.empty()){
                        operat = operators.top(); operators.pop();
                    }
                    if(operat == '&'){
                        bool ans = true;
                        while(true){
                            char curr = values.top(); values.pop();
                            if(curr == '(')break;
                            bool val = curr=='t'? true : false;
                            ans = ans&&val;
                        }
                        values.push(ans?'t':'f');
                    } else if(operat == '|'){
                        bool ans = false;
                        while(true){
                            char curr = values.top(); values.pop();
                            if(curr == '(')break;
                            bool val = curr=='t'? true : false;
                            ans = ans||val;
                        }
                        values.push(ans?'t':'f');
                    } else if(operat == '!'){
                        char curr = values.top(); values.pop();
                        values.pop(); // popped (
                        values.push(curr == 'f' ? 't':'f'); 
                    }
                } else {
                    values.push(ch);
                }
            }
        }
        return values.top()=='t'? true : false;
    }

    bool isOperator(char& ch){
        return ch =='!' || ch == '&' || ch == '|';
    }
};