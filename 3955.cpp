class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> vect;
        string curr = "";
        int currSum = 0;
        populate(vect, n, k, curr, currSum);
        return vect;
    }

    void populate(auto& vect, auto& n, auto& k, auto& curr, auto& sum){
        if(curr.size() == n){
            vect.push_back(curr);
            return;
        }

        curr+='0';
        populate(vect, n, k, curr, sum);
        curr.pop_back();

        if(curr.empty() || curr.back() == '0'){
            curr+='1';
            int ss = curr.size()-1;;
            sum+=ss;
            if(sum <= k){
                populate(vect, n, k, curr, sum);
            }
            curr.pop_back();
            sum-=ss;
        }
    }
};
