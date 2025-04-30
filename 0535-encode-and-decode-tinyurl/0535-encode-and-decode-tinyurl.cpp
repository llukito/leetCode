class Solution {
public:

    unordered_map<string, string> map;
    int index = 0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortened = to_string(index++);
        map[shortened] = longUrl;
        return shortened;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));