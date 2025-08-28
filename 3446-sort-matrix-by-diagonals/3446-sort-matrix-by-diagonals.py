class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        for col in range(len(grid[0])-1, -1, -1):
            lis = []
            r = 0
            c = col
            while r>=0 and r<len(grid) and c>=0 and c<len(grid[0]):
                lis.append(grid[r][c])
                r+=1
                c+=1
            lis.sort()
            r = 0
            c = col
            idx = 0
            while r>=0 and r<len(grid) and c>=0 and c<len(grid[0]):
                grid[r][c] = lis[idx]
                idx+=1
                r+=1
                c+=1
        for row in range(len(grid)):
            lis = []
            r = row
            c = 0
            while r>=0 and r<len(grid) and c>=0 and c<len(grid[0]):
                lis.append(grid[r][c])
                r+=1
                c+=1
            lis.sort(reverse = True)
            r = row
            c = 0
            idx = 0
            while r>=0 and r<len(grid) and c>=0 and c<len(grid[0]):
                grid[r][c] = lis[idx]
                idx+=1
                r+=1
                c+=1
        return grid