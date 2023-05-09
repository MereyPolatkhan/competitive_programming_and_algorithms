class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        ans = 0
        for i in range(len(nums)):
            ans = ans ^ i ^ nums[i]
        ans ^= len(nums)
        return ans
    # space O(1)
    # time O(n)


class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        a = 0
        for i in range(len(nums)): # O(n)
            a += (i - nums[i]) 
        return a + len(nums)
    # space O(1)
    # time O(n)


class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        sum1 = sum(nums) # O(n)
        sum2 = 0
        for i in range(len(nums) + 1): # O(n)
            sum2 += i
        return sum2 - sum1
    # space O(1)
    # time O(2n)

class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        for i in range(0, len(nums) + 1):
            if (i not in nums):
                return i
    # O(n^2) time 
    # O(1) space