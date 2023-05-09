# https://leetcode.com/problems/search-insert-position/
# 35. Search Insert Position

class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while(left <= right):
            mid = (left + right) // 2
            if (nums[mid] == target):
                return mid 

            elif (nums[mid] < target):
                left = mid + 1

            elif (target < nums[mid]):  
                right = mid - 1

        return left