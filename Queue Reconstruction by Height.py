#sort in desc order->if equal height->sort according to number of people before them
def compare(a,b):
    if a[0]>b[0]:
        return -1
    if a[0]<b[0]:
        return 1
    else:
        if a[1]>b[1]:
            return 1
        else:
            return -1
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people=sorted(people,key=cmp_to_key(compare))
        ans=list()
        for l in people:
            ans.insert(l[1],l)
        return ans
