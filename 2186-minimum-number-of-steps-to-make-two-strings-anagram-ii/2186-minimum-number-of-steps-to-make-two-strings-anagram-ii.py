class Solution:
    def minSteps(self, s: str, t: str) -> int:
        m1 = dict()
        m2 = dict()
        res = 0
        for ch in s:
            m1[ch] = m1.get(ch,0)+1
        for ch in t:
            m2[ch] = m2.get(ch,0)+1
        for key in m1:
            if m1[key]>m2.get(key,0):
                res+=m1[key]-m2.get(key,0)
        for key in m2:
            if m2[key]>m1.get(key,0):
                res+=m2[key]-m1.get(key,0)
        return res
        
