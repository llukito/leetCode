class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        left = 0
        maxPos = max(position)
        minPos = min(position)
        right = maxPos-minPos
        def possible(n):
            count = 1
            last = position[0]
            for i in range(1, len(position)):
                if(position[i]-last >=n):
                    last = position[i]
                    count+=1
                    if(count >= m):return True
            return False

        while(left <= right):
            mid = left + (right-left)//2
            if(possible(mid)):
                left = mid + 1
            else :
                right = mid - 1
        return left - 1
