#here firstly we will send all persons to city A then we will send half persons to city B sorted according to their difference
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        ans=0
        diff=list()
        for l in costs:
            ans=ans+l[0]
            diff.append(l[1]-l[0])
        diff.sort()
        n=int(len(costs)/2)
        for i in range(n):
            ans=ans+diff[i]
        
        return ans
        
        
        
        
#Alternate soln
# for input [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
#sorted list will be [[259, 770], [184, 139], [577, 469], [926, 667], [448, 54], [840, 118]] (Sorted according to their difference)
# Send first half persons to city A and next half persons to city B
from functools import cmp_to_key
def compare(a,b):
    if a[0]-a[1]>b[0]-b[1]:
        return 1
    elif a[0]-a[1]<b[0]-b[1]:
        return -1
    return 0
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        ans=0
        COSTS=sorted(costs,key=cmp_to_key(compare))
        
        for i in range(int(len(COSTS))):
            if i<(len(COSTS)/2):
                ans=ans+COSTS[i][0]
            else:
                ans=ans+COSTS[i][1]
        return ans
