class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        curr = ""
        prev = float('-inf')
        for ch in s:    
            if('0'<=ch<='9'):
                curr+=ch
            elif  curr!="" :
                if( prev >= int(curr)): return False
                prev = int(curr)
                curr = ""
        if(curr!=""):
            if( prev >= int(curr)): return False
        return True