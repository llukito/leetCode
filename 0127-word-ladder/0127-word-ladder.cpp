class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(endWord) == wordSet.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int lvl = 1;
        while(!q.empty()){
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                string s = q.front(); q.pop();
                if (s == endWord) return lvl;
                for (int i = 0; i < s.size(); ++i) {
                    string temp = s;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (wordSet.count(temp)) {
                            q.push(temp);
                            wordSet.erase(temp); 
                        }
                    }
                }
            }
            lvl++;
        }
        return 0;
    }
};