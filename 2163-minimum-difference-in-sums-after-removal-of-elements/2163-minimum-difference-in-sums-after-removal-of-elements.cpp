class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int len = nums.size();

        vector<long long> leftSum(len, 0);
        priority_queue<int> maxHeap;
        long long leftTotal = 0;

        for (int i = 0; i < 2 * n; ++i) {
            maxHeap.push(nums[i]);
            leftTotal += nums[i];
            if (maxHeap.size() > n) {
                leftTotal -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == n)
                leftSum[i] = leftTotal;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long rightTotal = 0;
        long long res = LLONG_MAX;

        for (int i = len - 1; i >= n; --i) {
            minHeap.push(nums[i]);
            rightTotal += nums[i];
            if (minHeap.size() > n) {
                rightTotal -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == n && i - 1 >= 0 && i - 1 < 2 * n)
                res = min(res, leftSum[i - 1] - rightTotal);
        }

        return res;
    }
};
