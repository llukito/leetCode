class Solution {
public:
    int mirrorDistance(int n) {
        return abs(stoi(myReverse(to_string(n))) - n);
    }

    string myReverse(string str){
        reverse(str.begin(), str.end());
        string res;
        bool b = false;
        for(char ch : str){
            if(ch != '0' || b){
                b = true;
                res+=ch;
            } 
        }
        return res;
    }
};
