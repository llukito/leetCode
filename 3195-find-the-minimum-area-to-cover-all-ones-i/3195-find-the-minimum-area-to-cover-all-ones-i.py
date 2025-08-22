class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        r1 = float('inf')
        c1 = float('inf')
        r2 = float('-inf')
        c2 = float('-inf')
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if(grid[r][c] == 1):
                    r1 = min(r1, r)
                    c1 = min(c1, c)
                    r2 = max(r2, r)
                    c2 = max(c2, c)
        return (r2-r1+1)*(c2-c1+1)