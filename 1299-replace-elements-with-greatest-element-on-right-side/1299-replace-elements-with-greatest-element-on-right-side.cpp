class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for(int i=0; i<arr.size()-1; i++){
            int mx = INT_MIN;
            for(int j=i+1; j<arr.size(); j++){
                mx = max(mx, arr[j]);
            }
            arr[i]=mx;
        }
        arr[arr.size()-1]=-1;
        return arr;
    }
};