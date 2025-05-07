class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> vect;
        string curr = "";
        fill(vect, curr, n);
        return k-1 >= vect.size() ? "" : vect[k-1];
    }

    void fill(vector<string>& vect, string& curr, int n){
        if(curr.length()==n){
            vect.push_back(curr);
            return;
        }
        for(int i=0; i<=2; i++){
            char ch = (char)('a'+i);
            if(curr.empty() || curr.back()!=ch){
                curr+=ch;
                fill(vect, curr, n);
                curr.pop_back();
            }
        }
    }
};