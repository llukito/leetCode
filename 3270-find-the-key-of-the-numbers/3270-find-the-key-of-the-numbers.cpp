class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string res;
        string s1 = trans(num1);
        string s2 = trans(num2);
        string s3 = trans(num3);
        for(int i=0; i<4; i++){
            char ch = '9';
            ch = min(ch, s1[i]);
            ch = min(ch, s2[i]);
            ch = min(ch, s3[i]);
            res+=ch;
        }
        return stoi(res);
    }
    
    string trans(int num1){
        string s1;
        for(int i=0; i<4-to_string(num1).length(); i++){
            s1+='0';
        }
        s1 += to_string(num1);
        return s1;
    }
};