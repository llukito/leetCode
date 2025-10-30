class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<>> pq;
        for(int n : nums){
            pq.push(n);
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top()); pq.pop();
        }
        return res;
    }
};