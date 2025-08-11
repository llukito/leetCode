class Solution:
    def getLucky(self, s: str, k: int) -> int:
        string = ""
        for ch in s:
            string += str(ord(ch)-ord('a')+1)
        curr = 0
        for i in range(k):
            res = 0
            for ch in string:
                res+=(ord(ch)-ord('0'))
            string = str(res)
        return int(string) 
        