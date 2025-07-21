class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix(arr.size()+1, 0);
        for(int i=0; i<arr.size(); i++){
            prefix[i+1] = prefix[i]^arr[i];
        }
        vector<int> res;
        for(auto& vect : queries){
            int start = vect[0]; int end = vect[1];
            res.push_back(prefix[end+1] ^ prefix[start]);
        }
        return res;
    }
};