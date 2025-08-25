class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        up = True
        size = len(mat)+len(mat[0])-1
        res = []
        cr = 0
        cc = 0
        while size!=0 :
            size-=1
            if up :
                while True:
                    res.append(mat[cr][cc])
                    if(not(cr-1>=0 and cc+1<len(mat[0]))):break
                    cc+=1
                    cr-=1
                if(cc==len(mat[0])-1):
                    cr+=1
                cc = min(cc+1, len(mat[0])-1)
                up = False
            else:
                while True:
                    res.append(mat[cr][cc])
                    if(not(cr+1<len(mat) and cc-1>=0)):break
                    cc-=1
                    cr+=1
                if(cr==len(mat)-1):
                    cc+=1
                cr = min(cr+1, len(mat)-1)
                up = True
        return res
