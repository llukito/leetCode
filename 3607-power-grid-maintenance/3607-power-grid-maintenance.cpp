class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // build adjacency list (1-based nodes)
        vector<vector<int>> graph(c + 1);
        for (auto &e : connections) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // compIndex[node] = index of component in components vector
        vector<int> compIndex(c + 1, -1);
        vector< set<int> > components; // each set holds currently online stations for that component

        // find connected components (iterative DFS)
        for (int i = 1; i <= c; ++i) {
            if (compIndex[i] != -1) continue;
            int idx = components.size();
            set<int> curr;
            stack<int> st;
            st.push(i);
            compIndex[i] = idx; // mark early to avoid pushing multiple times
            while (!st.empty()) {
                int u = st.top(); st.pop();
                // insert u into current component's online set
                curr.insert(u);
                for (int v : graph[u]) {
                    if (compIndex[v] == -1) {
                        compIndex[v] = idx;
                        st.push(v);
                    }
                }
            }
            components.push_back(std::move(curr));
        }

        vector<int> result;
        result.reserve(queries.size());

        for (auto &q : queries) {
            int type = q[0], x = q[1];
            int idx = compIndex[x]; // every node 1..c has been assigned an index
            if (type == 1) {
                // maintenance check
                if (components[idx].empty()) {
                    result.push_back(-1);
                } else if (components[idx].count(x)) {
                    // x is online -> resolves itself
                    result.push_back(x);
                } else {
                    // x is offline -> smallest operational station in same grid
                    result.push_back(*components[idx].begin());
                }
            } else {
                // type == 2 : take x offline
                components[idx].erase(x);
            }
        }
        return result;
    }
};