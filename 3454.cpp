class Solution {
    struct Event {
        int y, type, x1, x2;
        bool operator<(const Event& other) const { return y < other.y; }
    };

    vector<double> x_coords;
    vector<int> count;
    vector<double> length;

    void update(int node, int start, int end, int l, int r, int val) {
        if (l >= r) return;
        if (start == l && end == r) {
            count[node] += val;
        } else {
            int mid = (start + end) / 2;
            update(2 * node, start, mid, l, min(r, mid), val);
            update(2 * node + 1, mid, end, max(l, mid), r, val);
        }

        if (count[node] > 0) {
            length[node] = x_coords[end] - x_coords[start];
        } else if (end - start == 1) {
            length[node] = 0;
        } else {
            length[node] = length[2 * node] + length[2 * node + 1];
        }
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        x_coords.clear();
        for (const auto& sq : squares) {
            x_coords.push_back(sq[0]);
            x_coords.push_back(sq[0] + sq[2]);
        }
        sort(x_coords.begin(), x_coords.end());
        x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());

        int m = x_coords.size();
        count.assign(4 * m, 0);
        length.assign(4 * m, 0.0);

        vector<Event> events;
        for (const auto& sq : squares) {
            int x1 = lower_bound(x_coords.begin(), x_coords.end(), sq[0]) - x_coords.begin();
            int x2 = lower_bound(x_coords.begin(), x_coords.end(), sq[0] + sq[2]) - x_coords.begin();
            events.push_back({sq[1], 1, x1, x2});
            events.push_back({sq[1] + sq[2], -1, x1, x2});
        }
        sort(events.begin(), events.end());

        double total_area = 0;
        for (size_t i = 0; i < events.size() - 1; ++i) {
            update(1, 0, m - 1, events[i].x1, events[i].x2, events[i].type);
            total_area += length[1] * (events[i + 1].y - events[i].y);
        }

        count.assign(4 * m, 0);
        length.assign(4 * m, 0.0);
        double current_area = 0;
        double target = total_area / 2.0;

        for (size_t i = 0; i < events.size() - 1; ++i) {
            update(1, 0, m - 1, events[i].x1, events[i].x2, events[i].type);
            double h = events[i + 1].y - events[i].y;
            double area_step = length[1] * h;

            if (current_area + area_step >= target) {
                return events[i].y + (target - current_area) / length[1];
            }
            current_area += area_step;
        }

        return 0.0;
    }
};
