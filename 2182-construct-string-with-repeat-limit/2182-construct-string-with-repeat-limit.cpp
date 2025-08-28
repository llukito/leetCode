class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char,int, greater<>> m;
        for (char ch : s) m[ch]++;

        string res;
        while (true) {
            auto it = m.begin();
            while (it != m.end() && it->second == 0) ++it;
            if (it == m.end()) break;

            char key = it->first;
            int value = it->second;

            int take = min(value, repeatLimit);
            res.append(take, key);
            m[key] -= take;

            if (m[key] == 0) continue;

            auto it2 = next(it);
            while (it2 != m.end() && it2->second == 0) ++it2;
            if (it2 == m.end()) break; 
            res.push_back(it2->first);
            m[it2->first]--;
        }

        return res;
    }
};
