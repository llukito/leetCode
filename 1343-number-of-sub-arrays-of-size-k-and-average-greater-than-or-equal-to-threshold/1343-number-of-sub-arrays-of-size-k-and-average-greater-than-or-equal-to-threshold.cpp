class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        vector<int> prefix(arr.size()+1, 0);
        prefix[0] = 0;
        for(int i=0; i<arr.size(); i++){
            prefix[i+1] = prefix[i]+arr[i];
        }
        int left = 0; int right = k-1;
        while(right<arr.size()){
            int all = prefix[right+1]-prefix[left];
            if(all/k >= threshold)res++;
            right++; left++;
        }
        return res;
    }
};