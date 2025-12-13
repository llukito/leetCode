class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> vect;
        int n = code.size();
        for(int i = 0; i < n; i++){
            if(!code[i].empty() && validCode(code[i]) && validBusiness(businessLine[i]) && isActive[i]){
                vect.push_back(code[i]+'*'+businessLine[i]);
            }
        }

        sort(vect.begin(), vect.end(), customComparison);
        vector<string> ans;
        for(string s : vect){
            string ss = "";
            for(int i = 0; s[i] != '*'; i++){
                ss+=s[i];
            }
            ans.push_back(ss);
        }
        return ans;
    }

    static bool customComparison(string& str1, string& str2){
        auto t1 = getCategory(str1); auto t2 = getCategory(str2);
        string category1 = t1.first; int code1 = t1.second;
        string category2 = t2.first; int code2 = t2.second;

        if(category1 == category2){
            return code1 < code2;
        } else {
            return category1 < category2;
        }
    }

    static pair<string, int> getCategory(string& str){
        string code = "";
        for(int i = 0 ; i < str.size(); i++){
            if(isdigit(str[i])){
                code+=str[i];
            }
            if(str[i] == '*'){
                string id = "";
                i++;
                for(; i < str.size(); i++){
                    id+=str[i];
                }
                return {id, stoi(code)};
            }
        }
        return {"NULL", -1};
    }

    bool validCode(string& str){
        for(char ch : str){
            ch = tolower(ch);
            if(!isalnum(static_cast<unsigned char>(ch)) && ch != '_')return false;
        }
        return true;
    }

    bool validBusiness(string& str){
        return (str == "electronics") || (str == "grocery") || (str == "pharmacy") || (str == "restaurant");
    }
};