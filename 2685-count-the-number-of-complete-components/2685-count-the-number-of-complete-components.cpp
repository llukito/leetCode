class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        getGraph(graph, edges);
        unordered_set<int> visited;
        int components = 0;
        for(int i=0; i<n; i++){
            if(!visited.count(i)){
                int edges = 0;
                int nodes = 0;
                dfs(i, graph, visited, edges, nodes);
                if((nodes*(nodes-1))/2 == edges/2){
                    components++;
                }
            }
        }
        return components;
    }

    void dfs(int i, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int& edges, int& nodes){
        stack<int> st;
        st.push(i);
        while(!st.empty()){
            int num = st.top(); st.pop();
            if(!visited.count(num)){
                nodes++;
                edges+=graph[num].size();
                visited.insert(num);
                for(int n : graph[num]){
                    if(!visited.count(n)){
                        st.push(n);
                    }
                }
            }
        }
    }

    void getGraph(unordered_map<int, vector<int>>& graph, vector<vector<int>>& edges){
        for(vector<int> vect : edges){
            graph[vect[0]].push_back(vect[1]);
            graph[vect[1]].push_back(vect[0]);
        }
    }
};