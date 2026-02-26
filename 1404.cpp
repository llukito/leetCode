class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while(true){
            if(s.size() == 1 && stoi(s) == 1)break;
            if(s.back() == '0'){
                s = s.substr(0, s.size()-1);
            } else {
                int carry = 1;
                for(int i = 0; i < s.size(); i++){
                    int curr = s[s.size()-1-i]-'0';
                    if(curr == 0){
                        s[s.size()-1-i] = (to_string(carry))[0];
                        carry = 0;
                    } else if(curr == 1 && carry == 0){
                       //nothing
                    } else {
                        s[s.size()-1-i] = '0';
                        carry = 1;
                    }
                }
                if(carry == 1){
                    s.insert(s.begin(), '1');
                }
            }
            steps++;
            cout<<s<<endl;
        }
        return steps;
    }
};
