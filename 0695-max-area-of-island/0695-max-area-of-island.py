class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        used = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        res = 0
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if used[r][c] == 0 and grid[r][c] == 1 :
                    curr = [0]
                    self.check(curr, used, grid, r, c)
                    res = max(res, curr[0])
        return res

    def check(self, curr:List[int], used: List[List[int]], grid: List[List[int]], r:int, c:int) -> None:
        if r<0 or r>=len(grid) or c<0 or c>=len(grid[0]) : return
        if grid[r][c] == 0 : return
        if(used[r][c] == 1) : return
        used[r][c] = 1
        curr[0]+=1
        self.check(curr, used, grid, r+1, c)
        self.check(curr, used, grid, r, c+1)
        self.check(curr, used, grid, r-1, c)
        self.check(curr, used, grid, r, c-1)
