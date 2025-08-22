class Solution:
    def similarPairs(self, words: List[str]) -> int:
        res = 0
        for i in range(len(words)):
            for j in range(i+1, len(words)):
                if self.poss(words[i],words[j]):
                    res+=1
        return res
    
    def poss(self, i, j):
        for n in j :
            if not n in i : return False
        for n in i:
            if not n in j: return False
        return True