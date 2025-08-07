class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<string> vect;
        fill(vect, candidates);
        int res = 0;
        for(int i=0; i<24; i++){
            int num = 0;
            for(string str : vect){
                if(str[i]=='1')num++;
            }
            res = max(res, num);
        }
        return res;
    }

    void fill(vector<string>& vect, vector<int>& candidates){
        for(int n : candidates){
            vect.push_back(transform(n));
        }
    }

    string transform(int n){
        string curr;
        while(n!=0){
            if(n%2==0){
                curr+='0';
            } else {
                curr+='1';
            }
            n/=2;
        }
        int size = curr.size();
        for(int i=0; i<24-size; i++){
            curr+='0';
        }
        reverse(curr.begin(), curr.end());
        return curr;
    }
};