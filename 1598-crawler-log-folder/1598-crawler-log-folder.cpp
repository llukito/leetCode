class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps = 0;
        for(string str : logs){
            if(str == "./")continue;
            if(str == "../"){
                steps = max(steps-1, 0);
            } else {
                steps++;
            }
        }
        return steps;
    }
};