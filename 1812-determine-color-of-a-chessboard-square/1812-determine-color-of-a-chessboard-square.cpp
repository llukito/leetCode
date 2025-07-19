class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (coordinates[0]-'a') % 2 == 0 ? (coordinates[1]-'1') % 2 == 0 ? false : true : (coordinates[1]-'1') % 2 == 0 ? true : false;
    }
};