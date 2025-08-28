class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        for(int i=0; i<rating.size()-2; i++){
            for(int j=i+1; j<rating.size()-1; j++){
                for(int k=j+1; k<rating.size(); k++){
                    int ri = rating[i]; int rj = rating[j]; int rk = rating[k];
                    if((ri<rj && rj<rk) || (ri>rj && rj>rk))res++;
                }
            }
        }
        return res;
    }
};