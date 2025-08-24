class Solution:
    def findKOr(self, nums: List[int], k: int) -> int:
        lis = []
        for n in nums:
            st = format(n, '032b')
            lis.append(st)
        res = ""
        for i in range(0, 32):
            al = 0
            for n in lis:
                if(n[i]=='1'):al+=1
                if(al>=k):break
            if(al>=k):res+='1'
            else:res+='0'
        return int(res,2)