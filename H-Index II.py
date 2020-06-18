class Solution:
    def hIndex(self, citations: List[int]) -> int:
        low=0
        ans=0
        n=len(citations)
        if n==0:
            return 0
        high=len(citations)-1
        while low<=high:
            h=low+int((high-low)/2)
            if citations[h]>=(n-h):
                high=h-1
                ans=n-h
            else:
                low=h+1
        return ans
