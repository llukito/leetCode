class Solution {
public:
    string fractionToDecimal(int numerat, int denominat) {
        long long numerator = numerat; long long denominator = denominat;
        if(numerator%denominator == 0) {
            return to_string(numerator/denominator);
        }
        if(numerator == 0){
            return "0";
        }
        bool b = false;
        if((numerator<0 && denominator>0) || (numerator>0 && denominator<0) ){
            b = true;
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        vector<pair<string,int>> vect;
        int start = numerator/denominator;
        string res = to_string(start) + ".";
        int begin = res.length();
        numerator-= start*denominator;
        unordered_set<string> ss;
        while(true){
            numerator*=10;
            int curr = numerator/denominator;
            res+=to_string(curr);
            numerator-= curr*denominator;
            if(numerator == 0)break;
            string key = to_string(curr)+to_string(numerator);
            vect.push_back({key, numerator});
            if(ss.count(key)){
                res[res.length()-1] = ')';
                for(int i=begin; i<res.length()-1; i++){
                    if(vect[i-begin].first == key){
                        res.insert(i, "(");
                        break;
                    }
                }
                break;
            }
            ss.insert(key);
        }
        if(b){
            return "-"+res;
        }
        return res;
    }
};