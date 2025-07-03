class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<int> indexes;
        for(int i = 0; i<s.length(); i++){
            indexes.push_back(i);
        }
        vector<vector<int>> var;
        vector<int> curr;
        fill(var, curr, indexes, 0);
        vector<string> result;
        for(vector<int> vect : var){
            string temp = s;
            int c = 0;
            for(int i : vect){
                temp.insert(i+1+c++, ".");
            }
            if(valid(temp)){
                result.push_back(temp);
            }
        }
        return result;
    }

    void fill(vector<vector<int>>& var, vector<int>& curr, vector<int>& indexes, int idx){
        if(curr.size()==3){
            var.push_back(curr);
            return;
        }
        if(idx == indexes.size())return;
        fill(var, curr, indexes, idx+1);
        curr.push_back(indexes[idx]);
        fill(var, curr, indexes, idx+1);
        curr.pop_back();
    }

    bool valid(string str){
        string curr;
        long long num = 0;
        for(char ch : str){
            if(ch == '.'){
                if(curr.empty())return false;
                if(curr[0] == '0'){
                    if(curr.size()>1)return false;
                }
                if(num<0 || num>255)return false;
                curr = "";
                num = 0;
            } else if(ch >='0' && ch<='9'){
                if(curr.size()>3)return false;
                curr+=ch;
                num*=10;
                num+=ch-'0';
            } else {
                return false;
            }
        }
        if(curr.empty())return false;
        if(curr[0] == '0'){
            if(curr.size()>1)return false;
        }
        if(num<0 || num>255)return false;
        curr = "";
        num = 0;
        return true;
    }
};