class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        suffix = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suffix[i] = suffix[i + 1] + piles[i]
        @lru_cache(None)
        def check(i, M):
            if(i>=len(piles)):return 0
            if 2 * M >= n - i:
                return suffix[i]
            s = 0
            for j in range(1, 2*M+1): 
                s = max(s, suffix[i] - check(i + j, max(M, j)))
            return s
        return check(0,1)

