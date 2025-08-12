class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        arr = []
        for r in range(len(mat)):
            ones = 0
            for c in range(len(mat[0])):
                if mat[r][c]==1:ones+=1
            arr.append((ones, r))
        arr.sort()
        res = []
        for i in range(k):
            res.append(arr[i][1])
        return res