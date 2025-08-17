class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> priorities;
        for(int i=0; i<order.size(); i++){
            priorities[order[i]] = order.size()-i;
        }
        priority_queue<pair<int, char>> pq;
        for(char ch : s){
            int priority = INT_MIN;
            if(priorities.count(ch)){
                priority = priorities[ch];
            }
            pq.push({priority, ch});
        }
        string str;
        while(!pq.empty()){
            str+=pq.top().second; pq.pop();
        }
        return str;
    }
};