/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return fill(grid, 0,0, grid.size()-1, grid.size()-1);
    }

    Node* fill(vector<vector<int>>& grid, int r1, int c1, int r2, int c2){
        if (r1 == r2 && c1 == c2) {
            return new Node(grid[r1][c1], true);
        }
        Node* res = new Node();
        int val = grid[r1][c1];
        bool b = true;
        for(int r=r1; r<=r2; r++){
            for(int c=c1; c<=c2; c++){
                if(grid[r][c]!=val){
                    b = false;
                    break;
                }
            }
            if(!b)break;
        }
        if(b){
            res->isLeaf = true;
            res->val = val;
            res->topLeft = nullptr;
            res->topRight = nullptr;
            res->bottomLeft = nullptr;
            res->bottomRight = nullptr;
        } else {
            int rm = (r1 + r2) / 2;
            int cm = (c1 + c2) / 2;
            res->isLeaf = false;
            res->val = val;
            res->topLeft = fill(grid, r1, c1, rm, cm);
            res->topRight = fill(grid, r1, cm + 1, rm, c2);
            res->bottomLeft = fill(grid, rm + 1, c1, r2, cm);
            res->bottomRight = fill(grid, rm + 1, cm + 1, r2, c2);
        }
        return res;
    }
};