class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int next = 0;
        for(int i=0; i<data.size(); i++){
            bitset<8> b(data[i]);
            string s = b.to_string();
            if(s[0] == '0'){
                if(next != 0)return false;
            } else {
                if(next > 0){
                    if(s[0]=='1' && s[1] == '0'){
                        next--;
                        continue;
                    } else {
                        return false;
                    }
                }
                if(s[0]=='1' && s[1] == '0')return false;
                int all = 0; int idx = 0;
                while(s[idx]=='1'){
                    idx++;
                    all++;
                }
                if(all>4)return false;
                next = all-1;
            }
        }
        return next == 0;
    }
};