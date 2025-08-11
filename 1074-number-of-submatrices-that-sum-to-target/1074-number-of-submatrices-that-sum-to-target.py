class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        rows = len(matrix) 
        cols = len(matrix[0])
        res = 0
        for top in range(rows):
            list = [0 for _ in range(cols)]
            for bottom in range(top, rows):
                for c in range(cols):
                    list[c]+=matrix[bottom][c]
                map = {0:1}
                val = 0
                for i in list:
                    val+=i
                    res+=map.get(val-target,0)
                    map[val] = map.get(val,0)+1
        return res 

