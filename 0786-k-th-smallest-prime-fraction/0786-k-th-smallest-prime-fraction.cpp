// leetcode number 786 (K-th Smallest Prime Fraction)
class Solution {
public:
    // we use custom sort for priority queue
    struct compare {
        bool operator()(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
            return get<0>(a) * get<1>(b) > get<0>(b) * get<1>(a);
        }
    };

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, compare> pq;
        for (int i = 1; i < arr.size(); i++) {
            pq.push(make_tuple(1, arr[i], 0, i));
        }
        vector<vector<int>> res;
        while (!pq.empty() && res.size() != k) {
            tuple<int, int, int, int> t = pq.top(); pq.pop();
            res.push_back({ get<0>(t), get<1>(t) });
            if (get<2>(t) < arr.size() && get<2>(t) + 1 != get<3>(t)) {
                pq.push(make_tuple(arr[get<2>(t) + 1], get<1>(t), get<2>(t) + 1, get<3>(t)));
            }
        }
        return res.back();
    }
};