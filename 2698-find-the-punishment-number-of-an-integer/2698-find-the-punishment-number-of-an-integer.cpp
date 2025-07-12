class Solution {
public:
    int punishmentNumber(int n) {
        int sum = 0;
        for(int i=1; i<=n; i++){
            int num = i*i;
            string str = to_string(num);
            vector<string> parts;
            bool b = false;
            check(str, parts, 0, b, "", i);
            if(b){
                if(i == 37){
                    for(string str : parts){
                        cout<<str<<" ";
                    }
                    cout<<endl;
                }
                sum+=num;
            }
        }
        return sum;
    }

    void check(string str, vector<string>& parts, int index, bool& b, string curr, int i){
        if(b)return;
        if(index == str.length()){
            int res = 0;
            for(string s : parts){
                if(s.empty())continue;
                res+=stoi(s);
            }
            if(res == i){
                b = true;
            }
            return;
        }
        curr+=str[index];
        if(index+1 != str.length()){
            check(str, parts, index+1, b, curr, i);
        }
        parts.push_back(curr);
        check(str, parts, index+1, b, "", i);
        parts.pop_back();
    }
};