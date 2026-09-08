class Solution {
public:
    int maxProduct(int n) {
        vector<int> vect;
        while(n!=0){
            int rem = n%10;
            vect.push_back(rem);
            n/=10;
        }
        sort(vect.begin(), vect.end());
        return vect[vect.size()-1]*vect[vect.size()-2];
    }
};
