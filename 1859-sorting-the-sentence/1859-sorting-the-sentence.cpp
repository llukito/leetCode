class Solution {
public:
    string sortSentence(string s) {
        priority_queue<pair<int,string>, vector<pair<int,string>>, greater<>> pq;
        string curr;
        for(char ch : s){
            if(ch == ' '){
                pq.push({curr.back()-'0', curr.substr(0,curr.size()-1)});
                curr = "";
            } else {
                curr+=ch;
            }
        }
        pq.push({curr.back()-'0', curr.substr(0,curr.size()-1)});
        string res;
        while(!pq.empty()){
            res+=pq.top().second; pq.pop();
            res+=" ";
        }
        return res.substr(0, res.size()-1);
    }
};