class Solution {
public:
    string s;
    int k;

    bool isSubsequence(string& pattern) {
        int i = 0, j = 0, count = 0;
        int n = s.size();
        string repeat;
        for (int t = 0; t < k; ++t) repeat += pattern;
        for (char ch : s) {
            if (ch == repeat[j]) j++;
            if (j == repeat.size()) return true;
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string _s, int _k) {
        s = _s;
        k = _k;

        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        // Build initial pool of characters that can appear in the answer
        string candidates = "";
        for (char ch = 'z'; ch >= 'a'; --ch) {
            if (freq[ch] >= k)
                candidates += ch;
        }

        queue<string> q;
        q.push("");
        string result = "";

        while (!q.empty()) {
            string curr = q.front(); q.pop();

            // Try appending all possible next characters (in reverse lex order)
            for (char ch : candidates) {
                string next = curr + ch;

                // Limit max length of candidate
                if (next.length() > s.length() / k) continue;

                if (isSubsequence(next)) {
                    // Found a valid one → update result if longer or better
                    if (next.length() > result.length() || 
                        (next.length() == result.length() && next > result)) {
                        result = next;
                    }
                    // Push for further exploration
                    q.push(next);
                }
            }
        }

        return result;
    }
};
