class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        res = []
        for s in words[0]:
            res.append(s)
        for st in words:
            temp = []
            for ch in st:
                if(ch in res):
                    temp.append(ch)
                    res.remove(ch)
                
            res = temp
        return res
