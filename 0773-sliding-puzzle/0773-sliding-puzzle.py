class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        q = deque()
        desired = "123450"
        curr = ""
        for r in range(2):
            for c in range(3):
                curr+=str(board[r][c])
        q.append(curr)
        steps = 0
        visited = set()
        while q :
            size = len(q)
            for i in range(size):
                cu = q.popleft()
                if(cu in visited):continue
                if(cu == desired):
                    return steps
                visited.add(cu)
                r,c = self.getIt(cu)
                if(r+1 < 2):
                    i = 3*r+c
                    j = 3*r+c+3
                    lst = list(cu)
                    lst[i], lst[j] = lst[j], lst[i]
                    cu = "".join(lst) 
                    if(not cu in visited):
                        q.append(cu)
                    i = 3*r+c
                    j = 3*r+c+3
                    lst = list(cu)
                    lst[i], lst[j] = lst[j], lst[i]
                    cu = "".join(lst) 
                if(r-1>=0):
                    i = 3*r+c
                    j = 3*r+c-3
                    lst = list(cu)
                    lst[i], lst[j] = lst[j], lst[i]
                    cu = "".join(lst) 
                    if(not cu in visited):
                        q.append(cu)
                    i = 3*r+c
                    j = 3*r+c-3
                    lst = list(cu)
                    lst[i], lst[j] = lst[j], lst[i]
                    cu = "".join(lst) 
                if(c+1 < 3):
                    i = 3*r+c
                    j = 3*r+c+1
                    lst = list(cu)
                    lst[i], lst[j] = lst[j], lst[i]
                    cu = "".join(lst) 
                    if(not cu in visited):
                        q.append(cu)
                    i = 3*r+c
                    j = 3*r+c+1
                    lst = list(cu)
                    lst[i], lst[j] = lst[j], lst[i]
                    cu = "".join(lst) 
                if(c-1>=0):
                    i = 3*r+c
                    j = 3*r+c-1
                    lst = list(cu)
                    lst[i], lst[j] = lst[j], lst[i]
                    cu = "".join(lst) 
                    if(not cu in visited):
                        q.append(cu)
                    i = 3*r+c
                    j = 3*r+c-1
                    lst = list(cu)
                    lst[i], lst[j] = lst[j], lst[i]
                    cu = "".join(lst)
            steps+=1
        return -1

    def getIt(self, string):
        c = 0 
        r = 0
        for i in range(len(string)):
            if(string[i] == '0'):
                return r,c
            c+=1
            if(c == 3):
                c = 0
                r = 1
        return -1,-1