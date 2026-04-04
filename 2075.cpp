class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int bigSize = encodedText.size();
        int cols = bigSize/rows;
        int idx = 0;
        // fill grid
        vector<vector<char>> grid(rows, vector<char>(cols, ' '));
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                grid[r][c] = encodedText[idx++];
            }
        }
        // traverse
        string res;
        for(int c = 0; c < cols; c++){
            int currC = c; int currR = 0;
            while(currC < cols && currR < rows){
                res+=grid[currR++][currC++];
            }
        }
        // trim
        return trim(res);
    }

    string trim(const std::string& str) {
        size_t last = str.find_last_not_of(" \t\n\r");
        return str.substr(0, last + 1);
    }
};
