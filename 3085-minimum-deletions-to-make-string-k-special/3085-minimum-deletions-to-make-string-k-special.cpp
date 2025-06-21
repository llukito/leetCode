class Solution {
public:
    int minimumDeletions(string word, int k) {
        int freq[26] = {0};
        for (char ch : word)
            freq[ch - 'a']++;

        vector<int> counts;
        for (int i = 0; i < 26; ++i)
            if (freq[i] > 0)
                counts.push_back(freq[i]);

        int ans = INT_MAX;

        for (int x = 1; x <= *max_element(counts.begin(), counts.end()); ++x) {
            int deletions = 0;
            for (int f : counts) {
                if (f < x) deletions += f;
                else if (f > x + k) deletions += f - (x + k);
            }
            ans = min(ans, deletions);
        }

        return ans;
    }
};