class Solution {
public:
    string clearStars(string s) {
        stack<char> res;
        multiset<char> mult;
        for(char ch : s){
            if(ch != '*'){
                res.push(ch);
                mult.insert(ch);
            } else {
                int val = *mult.begin();
                mult.erase(mult.begin());
                stack<int> temp;
                while(!res.empty() && res.top()!=val){
                    temp.push(res.top());
                    res.pop();
                }
                if(!res.empty())res.pop();
                while(!temp.empty()){
                    res.push(temp.top());
                    temp.pop();
                }
            }
        }
        string str;
        while(!res.empty()){
            str+=res.top();
            res.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};