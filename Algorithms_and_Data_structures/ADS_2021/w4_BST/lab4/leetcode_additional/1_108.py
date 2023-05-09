# 108. Convert Sorted Array to Binary Search Tree


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def sortedArrayToBST(self, nums: list[int]):
        
        def recursion(left, right):
            if (left > right):
                return None
            mid = (left + right) // 2
            node = TreeNode(nums[mid])
            node.left = recursion(left, mid - 1)
            node.right = recursion(mid + 1, right)
            return node 
        
        return recursion(0, len(nums) - 1)