class Solution {
public:
    struct node {
        int idx;
        node *prev, *next;
        long long val;
        node(int id, node* p, node* n, long long v) : idx(id), prev(p), next(n), val(v) {}
    };

    int isViolation(node* n) {
        if (!n || !n->next) return 0;
        return (n->val > n->next->val) ? 1 : 0;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int steps = 0;
        int violations = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        node* prevNode = nullptr;
        node* root = nullptr;
        unordered_map<int, node*> mp;
        int n = nums.size();

        if (n <= 1) return 0;
        for (int i = 0; i < n; i++) {
            node* curr = new node(i, prevNode, nullptr, nums[i]);
            if (prevNode) prevNode->next = curr;
            if (i == 0) root = curr;
            mp[i] = curr;
            prevNode = curr;
            if (i < n - 1) pq.push({(long long)nums[i] + nums[i+1], i});
        }

        node* temp = root;
        while (temp) {
            violations += isViolation(temp);
            temp = temp->next;
        }

        while (violations > 0 && !pq.empty()) {
            auto [currSum, idx] = pq.top();
            pq.pop();

            if (mp[idx] == nullptr) continue;
            node* a = mp[idx];
            node* b = a->next;
            if (!b || (a->val + b->val != currSum)) continue;

            violations -= isViolation(a->prev);
            violations -= isViolation(a);
            violations -= isViolation(b);

            mp[b->idx] = nullptr;
            a->val = currSum;
            a->next = b->next;
            if (b->next) b->next->prev = a;
            delete b;

            violations += isViolation(a->prev);
            violations += isViolation(a);

            if (a->prev) pq.push({a->prev->val + a->val, a->prev->idx});
            if (a->next) pq.push({a->val + a->next->val, a->idx});

            steps++;
        }
        return steps;
    }
};
