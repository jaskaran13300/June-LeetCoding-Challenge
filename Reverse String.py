# life is too short use python
class Solution:
    def reverseString(self, s: List[str]) -> None:
        s.reverse()


#alternate
class Solution:
    def reverseString(self, s: List[str]) -> None:
        st=0
        en=int(len(s))-1
        for st in range(int(len(s)/2)):
            s[st],s[en]=s[en],s[st]
            en=en-1
