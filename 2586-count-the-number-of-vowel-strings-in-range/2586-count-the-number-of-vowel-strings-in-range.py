class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        se = {"a","e","i","o","u"}
        res = 0
        for i in range(left, right+1):
            st = words[i]
            ch1 = st[0]
            ch2 = st[-1]
            if(ch1 in se and ch2 in se):res+=1
        return res