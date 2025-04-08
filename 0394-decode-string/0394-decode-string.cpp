class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strings;
        string curr = "";
        int num=0;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(isdigit(ch)){
                num=num*10 + ch-'0';
            } else if(ch=='['){
                nums.push(num);
                strings.push(curr);
                curr=""; num=0;
            } else if(ch==']'){
                int n = nums.top(); nums.pop();
                string prev = strings.top();strings.pop();
                string copyOfCurr = curr;
                curr=prev;
                for(int j=0; j<n; j++){
                    curr+=copyOfCurr;
                }
            } else {
                curr+=ch;
            }
        }
        return curr;
    }
};