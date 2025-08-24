class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        lis = []
        for i in range(len(s)):
            ch = s[i]
            if(ch==c):
                lis.append(i)
        res = []
        for i in range(len(s)):
            t = float('inf')
            for n in lis:
                t = min(t, abs(n-i))
            res.append(t)
        return res
        