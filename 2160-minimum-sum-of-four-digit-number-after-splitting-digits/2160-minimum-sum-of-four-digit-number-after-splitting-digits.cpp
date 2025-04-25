class Solution {
public:
    int minimumSum(int num) {
        string str = to_string(num);
        string curr;
        int min_ = INT_MAX;
        fill(str, curr, 0, min_);
        return min_;
    }

    void fill(string& str, string& curr, int index, int& min_){
        if(index==str.size()){
            map<int,int> mp;
            for(char ch : curr){
                mp[ch]++;
            }
            string left;
            for(char ch : str){
                if(mp.count(ch) && mp[ch]!=0){
                    mp[ch]--;
                } else {
                    left+=ch;
                }
            }
            if(left.empty() || curr.empty())return;
            sort(left.begin(), left.end());
            sort(curr.begin(), curr.end());
            int sum = stoi(left)+stoi(curr);
            min_ = min(min_, sum);
            return;
        }
        fill(str, curr, index+1, min_);
        curr+=str[index];
        fill(str, curr, index+1, min_);
        curr.pop_back();
    }
};