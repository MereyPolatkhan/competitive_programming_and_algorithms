class Solution:
    def longestNiceSubarray(self, nums: list[int]) -> int:
        if (len(nums) == 1):
            return 1

        res = []
        
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] & nums[j] == 0:
                    if nums[i] not in res:
                        res.append(nums[i])
                    elif nums[i] not in res:
                        res.append(nums[j])

        nums.clear()
                    
        for i in range(len(res)):
            for j in range(i + 1, len(res)):
                if res[i] & res[j] == 0:
                    if res[i] not in nums:
                        nums.append(res[i])
                    elif res[i] not in nums:
                        nums.append(res[j])

        return(nums)

s = Solution()
print(s.longestNiceSubarray([3,1,5,11,13]))
print()
print(s.longestNiceSubarray([1,3,8,48,10]))