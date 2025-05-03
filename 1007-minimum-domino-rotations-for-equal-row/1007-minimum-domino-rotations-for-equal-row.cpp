class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> mp1;
        for(int n : tops){
            mp1[n]++;
        }

        unordered_map<int,int> mp2;
        for(int n : bottoms){
            mp2[n]++;
        }

        unordered_map<int,int> map;
        for(int i=0; i<tops.size(); i++){
            int top = tops[i];
            int bottom = bottoms[i];
            map[top]++;
            if(top!=bottom)map[bottom]++;
        }
        int minSwaps = INT_MAX;
        for(auto& entry : map){
            if(entry.second == tops.size()){
                int n1 = INT_MIN, n2 = INT_MIN;
                if(mp1.count(entry.first)){
                    n1 = tops.size()-mp1[entry.first];
                }
                if(mp2.count(entry.first)){
                    n2 = tops.size()-mp2[entry.first];
                }
                int res = -1;
                if(n1 == INT_MIN){
                    res = n2;
                } else if(n2 == INT_MIN){
                    res = n1;
                } else {
                    res = min(n1,n2);
                }
                minSwaps = min(minSwaps, res);
            }
        }
        return minSwaps == INT_MAX ? -1 : minSwaps;
    }
};