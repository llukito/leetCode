// leetcode number 373 (Find K Pairs with Smallest Sums)
class Solution {
public:
    // we use custom sort for priority queue
    struct CompareSum {
        bool operator()(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
            return (get<0>(a) + get<1>(a)) > (get<0>(b) + get<1>(b));
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, CompareSum> pq;
        for (int i = 0; i < nums1.size(); i++) {
            pq.push(make_tuple(nums1[i], nums2[0], i, 0));
        }
        vector<vector<int>> result;
        int index = 1;
        while (!pq.empty()) {
            tuple<int, int, int, int> t = pq.top(); pq.pop();
            result.push_back({ get<0>(t), get<1>(t) });
            if (get<3>(t) + 1 < nums2.size()) {
                pq.push(make_tuple(nums1[get<2>(t)], nums2[get<3>(t) + 1], get<2>(t), get<3>(t) + 1));
            }
            if (result.size() == k)break;
        }
        return result;
    }
};