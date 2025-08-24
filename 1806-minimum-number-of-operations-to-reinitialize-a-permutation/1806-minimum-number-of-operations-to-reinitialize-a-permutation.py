class Solution:
    def reinitializePermutation(self, n: int) -> int:
        perm = [0]*n
        for i in range(n):
            perm[i] = i
        rem = perm
        steps = 0
        while True:
            steps+=1
            arr = [0]*n
            for i in range(len(perm)):
                if(i%2==0):
                    arr[i] = perm[i//2]
                else:
                    arr[i] = perm[n // 2 + (i - 1) // 2]
            perm = arr
            if perm == rem : break
        return steps