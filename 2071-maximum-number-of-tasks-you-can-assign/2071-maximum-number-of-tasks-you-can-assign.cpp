class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int left = 0, right = min(tasks.size(), workers.size()), ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

private:
    bool canAssign(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> avail(workers.end() - mid, workers.end());
        for (int i = mid - 1; i >= 0; --i) {
            int req = tasks[i];
            auto it = avail.lower_bound(req);
            if (it != avail.end()) {
                avail.erase(it);
            }
            else if (pills > 0) {
                it = avail.lower_bound(req - strength);
                if (it == avail.end()) return false;
                avail.erase(it);
                --pills;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
