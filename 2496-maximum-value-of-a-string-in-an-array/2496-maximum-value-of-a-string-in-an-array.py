class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        res = 0
        for s in strs:
            if self.isDigit(s):
                res = max(res, int(s))
            else:
                res = max(res, len(s))
        return res
    
    def isDigit(self, s):
        for ch in s:
            if(ord(ch)<ord('0') or ord(ch) > ord('9')) : return False
        return True