class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> map;
        for(string s : cpdomains){
            vector<string> vect = split(s);
            if(vect.size()==3){
                string str= vect[1];
                str+='.';
                str+=vect[2];
                map[str]+=stoi(vect[0]);
                map[vect[2]]+=stoi(vect[0]);
            } else {
                string str= vect[1];
                str+='.';
                str+=vect[2];
                str+=".";
                str+=vect[3];
                map[str]+=stoi(vect[0]);

                string str2;
                str2+=vect[2];
                str2+=".";
                str2+=vect[3];
                map[str2]+=stoi(vect[0]);
                map[vect[3]]+=stoi(vect[0]);
            }
        }
        vector<string> vect;
        for(auto& entry : map){
            string str = to_string(entry.second);
            str+=" ";
            str+=entry.first;
            vect.push_back(str);
        }
        return vect;
    }

    vector<string> split(const string& input) {
        regex re("[. ]");
        sregex_token_iterator it(input.begin(), input.end(), re, -1);
        sregex_token_iterator end;
        return vector<string>(it, end);
    }
};