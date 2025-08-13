class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        m = {}
        res = 0
        for i in range(lowLimit, highLimit+1):
            key = 0
            while i!=0 :
                key+=i%10
                i//=10
            m[key] = m.get(key,0)+1
            res = max(res, m[key])
        return res
            