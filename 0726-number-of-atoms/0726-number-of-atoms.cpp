class Solution {
public:
    string countOfAtoms(string formula) {
        stack<char> st;
        for(int i=0; i<formula.length(); i++){
            char ch = formula[i];
            if(ch!=')'){
                st.push(ch);
            } else{
                string str = "";
                while(true){
                    char c = st.top(); st.pop();
                    if(c == '(') break;
                    str+=c;
                }
                reverse(str.begin(), str.end());
                string numm = "";
                while(i+1<formula.length() && formula[i+1]>='0' && formula[i+1]<='9'){
                    numm+=formula[i+1];
                    i++;
                }
                int num = numm.empty() ? 1 : stoi(numm);
                cout<<str<<" -"<<num<<endl;
                string curr = ""; string n = "";
                string srn;
                for(int j=0; j<str.length(); j++){
                    char cha = str[j];
                    if(cha>='A' && cha<='Z'){
                        if(!curr.empty()){
                            srn+=curr;
                            int nn = n.empty() ? 1 : stoi(n);
                            int mult = nn*num;
                            if(mult>1){
                                srn+=to_string(mult);
                            }
                        }
                        curr = cha;
                        n.clear();
                    } else if(cha>='a' && cha<='z'){
                        curr+=cha;
                    } else if(cha>='0' && cha<='9'){
                        n+=cha;
                    }
                }
                if(!curr.empty()){
                    srn+=curr;
                    int nn = n.empty() ? 1 : stoi(n);
                    int mult = nn*num;
                    if(mult>1){
                        srn+=to_string(mult);
                    }
                }
                for(char ch : srn){
                    st.push(ch);
                }
                cout<<srn<<endl;
            }
        }
        string str = "";
        while(!st.empty()){
            str+=st.top(); st.pop();
        }
        reverse(str.begin(), str.end());
        string curr = ""; string n = "";
        map<string, int> m;
        for(int j=0; j<str.length(); j++){
            char cha = str[j];
            if(cha>='A' && cha<='Z'){
                if(!curr.empty()){
                    if(n.empty()){
                        m[curr] += 1;
                    } else {
                        m[curr] += stoi(n);
                    }
                }
                curr = cha;
                n.clear();
            } else if(cha>='a' && cha<='z'){
                curr+=cha;
            } else if(cha>='0' && cha<='9'){
                n+=cha;
            }
        }
        if(!curr.empty()){
            if(n.empty()){
                m[curr] += 1;
            } else {
                m[curr] += stoi(n);
            }
        }

        string result;
        for(auto& entry : m){
            result+=entry.first;
            if(entry.second > 1){
                result+=to_string(entry.second);
            }
        }
        return result;
    }
};