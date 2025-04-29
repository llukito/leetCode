class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> vect;
        for(int i=0; i<n; i++){
            vect.push_back(start+2*i);
        }
        int res = vect[0];
        for(int i=1; i<vect.size(); i++){
            res^=vect[i];
        }
        return res;
    }
};