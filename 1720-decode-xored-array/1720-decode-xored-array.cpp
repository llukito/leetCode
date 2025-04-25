class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> result(encoded.size()+1,first);
        for(int i=1; i<result.size(); i++){
            result[i]=encoded[i-1]^result[i-1];
        }

        return result;
    }
};