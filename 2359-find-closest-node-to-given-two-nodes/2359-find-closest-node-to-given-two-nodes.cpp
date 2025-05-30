class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int,int> map1 = calc(edges, node1);
        unordered_map<int,int> map2 = calc(edges, node2);
        int indx = -1;
        int val = INT_MAX;
        for(auto& entry : map1){
            if(map2.count(entry.first)){
                int n = max(entry.second, map2[entry.first]);
                cout<<entry.first<<" "<<n<<endl;
                if(n<val || (n == val && (indx == -1 || indx > entry.first))){
                    val = n;
                    indx = entry.first;
                }
            }
        }
        return indx;
    }

    unordered_map<int,int> calc(vector<int>& edges, int node1){
        queue<pair<int,int>> q1;
        unordered_set<int> set1;
        unordered_map<int, int> map1;
        q1.push({node1,0}); set1.insert(node1); map1[node1] = 0;
        while(!q1.empty()){
            int num = q1.front().first; int len = q1.front().second; q1.pop();
            if(edges[num] != -1 && !set1.count(edges[num])){
                set1.insert(edges[num]);        
                map1[edges[num]] = len + 1;
                q1.push({edges[num], len + 1});
            }
        }
        return map1;
    }
};