class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.idx = 0
        self.st = []
        self.fill(characters, combinationLength, 0, "")
        
    
    def fill(self, chars, ll, idx, curr) -> None:
        if(len(curr) == ll):
            self.st.append(curr)
            return
        if(idx == len(chars)):return
        curr+=chars[idx]
        self.fill(chars, ll, idx+1, curr)
        self.fill(chars, ll, idx+1, curr[:-1])

    def next(self) -> str:
        n = self.st[self.idx]
        self.idx+=1
        return n

    def hasNext(self) -> bool:
        return self.idx<len(self.st)


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()