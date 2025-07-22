class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true){
            if(s.length()<part.length())break;
            string temp;
            int size = part.size();
            int left = 0; int right = size-1;
            bool b = true;
            while(right<s.size()){
                string curr(s.begin()+left, s.begin()+right+1);
                if(curr == part){
                    left = right+1;
                    right = left+size-1;
                    b = false;
                }else {
                    temp+=s[left];
                    left++; right++;
                }
                if(right>=s.size()){
                    string stri(s.begin()+left, s.end());
                    temp+=stri;
                    break;
                }
            }
            if(b)break;
            s = temp;
        }
        return s;
    }
};