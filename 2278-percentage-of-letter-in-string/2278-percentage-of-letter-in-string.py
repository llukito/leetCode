class Solution:
    def percentageLetter(self, s: str, letter: str) -> int:
        n = len(s)
        num = 0
        for ch in s:
            if ch == letter :
                num+=1
        return int(num/n * 100)