// leetcode number 22 (Generate Parentheses)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        fill(res, 2*n, curr);
        return res;
    }

    void fill(vector<string>& res, int m, string& curr) {
        if (m == 0) {
            if (valid(curr)) {
                res.push_back(curr);
            }
            return;
        }
        curr += '(';
        fill(res, m - 1, curr);
        curr.pop_back();
        curr += ')';
        fill(res, m - 1, curr);
        curr.pop_back();
    }

    bool valid(string& curr) {
        stack<char> st;
        for (char ch : curr) {
            if (ch == '(') {
                st.push(ch);
            }
            else {
                if (st.empty())return false;
                if (st.top() != '(')return false;
                st.pop();
            }
        }
        return st.empty();
    }
};