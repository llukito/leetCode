class Solution {
public:
    unordered_map<string, vector<string>> memo;

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> vect;
        vector<string> curr;
        unordered_set<int> set;
        fill(words, groups, vect, curr, set, -1, 0, -1);
        return vect;
    }

    void fill(vector<string>& words, vector<int>& groups, vector<string>& res, vector<string>& curr,
              unordered_set<int>& set, int last_group, int index, int last_word_index) {

        string key = to_string(last_group) + "#" + to_string(last_word_index) + "#" + to_string(index);
        if (memo.count(key)) {
            if (curr.size() + memo[key].size() <= res.size()) return;
        }

        if (curr.size() > res.size()) {
            res = curr;
        }

        for (int i = index; i < words.size(); i++) {
            if (!set.count(i)) {
                if (last_group == -1 || last_group != groups[i]) {
                    if (curr.empty() || valid(curr.back(), words[i])) {
                        set.insert(i);
                        curr.push_back(words[i]);
                        fill(words, groups, res, curr, set, groups[i], i, i);
                        set.erase(i);
                        curr.pop_back();
                    }
                }
            }
        }

        memo[key] = vector<string>(res.begin() + curr.size(), res.end());
    }

    bool valid(string& s1, string& s2) {
        if (s1.length() != s2.length()) return false;
        int diff = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diff++;
                if (diff > 1) return false;
            }
        }
        return diff == 1;
    }
};
