class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> vect;
        if(n%2==1){
            vect.push_back(0);
            n--;
        }
        int idx = 1;
        for(int i=0; i<n/2; i++){
            vect.push_back(idx);
            vect.push_back(-idx);
            idx++;
        }
        return vect;
    }
};