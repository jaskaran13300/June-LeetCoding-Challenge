# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    ans=0
    def help(self,root,val):
        if root==None:
            return
        if root.left==None and root.right==None:
            val=val+str(root.val)
            self.ans=int(val)+self.ans
            return
        self.help(root.left,val+str(root.val))
        self.help(root.right,val+str(root.val))
            
    def sumNumbers(self, root: TreeNode) -> int:
        val=""
        if root is None:
            return 0
        self.help(root,val)
        return self.ans
