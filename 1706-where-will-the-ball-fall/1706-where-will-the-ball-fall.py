class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        res = []
        for c in range(len(grid[0])):
            b = False
            cc = c
            rr = 0
            while True:
                if grid[rr][cc] == 1 :
                    if((cc+1<len(grid[0]) and grid[rr][cc+1]==-1) or cc+1==len(grid[0]) ):
                        b = True
                        break
                    cc+=1
                    rr+=1
                else:
                    if((cc-1>=0 and grid[rr][cc-1]==1) or cc-1<0):
                        b = True
                        break
                    cc-=1
                    rr+=1
                if(rr == len(grid)):
                    res.append(cc)
                    break       
            if(b):
                res.append(-1)
        return res
