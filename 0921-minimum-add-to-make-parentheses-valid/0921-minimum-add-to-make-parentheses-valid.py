class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        stack = []
        for ch in s:
            if ch == '(':
                stack.append('(')
            else :
                if(stack and stack[-1] == '('):
                    stack.pop()
                else: 
                    stack.append(')')
        return len(stack)