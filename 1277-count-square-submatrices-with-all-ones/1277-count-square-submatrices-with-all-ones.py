class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        rows  =len(matrix)
        cols = len(matrix[0])
        res = 0
        for top in range(rows):
            list = [0 for _ in range(cols)]
            for bottom in range(top, rows):
                for i in range(cols):
                    list[i] +=matrix[bottom][i]
                n = bottom-top+1
                left = 0
                right = n-1
                while right < cols:
                    b = True
                    for i in range(left, right+1):
                        if(list[i] != n):
                            b = False
                            break
                    if(b):res+=1
                    left+=1
                    right+=1
        return res