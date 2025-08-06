class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int res = 0;
        vector<int> prefix;
        prefix.push_back(0);
        for(int i=0; i<arr.size(); i++){
            prefix.push_back(prefix.back()^arr[i]);
        }
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                int a = prefix[j]^prefix[i];
                for(int k=j; k<arr.size(); k++){
                    int b = prefix[k+1]^prefix[j];
                    if(a==b)res++;
                }
            }
        }
        return res;
    }
};