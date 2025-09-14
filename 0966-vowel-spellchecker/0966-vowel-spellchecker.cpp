class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> st(wordlist.begin(), wordlist.end());
        vector<string> res;
        vector<string> lowers;
        vector<string> changes;
        for(string s : wordlist){
            lowers.push_back(toLower(s));
        }
        for(int i=0; i<lowers.size(); i++){
            string temp = trans(lowers[i]);
            changes.push_back(temp);
        }
        for(string s : queries){
            if(st.count(s)){
                res.push_back(s);
                continue;
            }
            s = toLower(s);
            bool b = false;
            for(int i=0; i<wordlist.size(); i++){
                if(lowers[i] == s){
                    res.push_back(wordlist[i]);
                    b = true;
                    break;
                }
            }
            if(b)continue;
            s = trans(s);
            string r = "";
            for(int i=0; i<changes.size(); i++){
                if(changes[i] == s){
                    r = wordlist[i];
                    break;
                }
            }
            res.push_back(r);
        }
        return res;
    }

    string toLower(string s){
        string curr = "";
        for(char ch : s){
            curr+=tolower(ch);
        }
        return curr;
    }
    string trans(string s){
        set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        string curr = "";
        for(char ch : s){
            if(vowels.count(ch)){
                curr+="-";
            } else {
                curr+=ch;
            }
        }
        return curr;
    }
};