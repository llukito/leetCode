class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        res = 0
        for top in range(len(mat)):
            lis = [0 for _ in range(len(mat[0]))]
            for bottom in range(top, len(mat)):
                for c in range(len(mat[0])):
                    lis[c]+=mat[bottom][c]
                desired = bottom-top+1
                curr = 0
                for c in range(len(mat[0])):
                    if(lis[c] == desired):
                        curr+=1
                        res+=curr
                    else:
                        curr = 0
        return res

