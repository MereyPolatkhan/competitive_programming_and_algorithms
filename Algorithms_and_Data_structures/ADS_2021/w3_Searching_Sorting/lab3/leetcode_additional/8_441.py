# https://leetcode.com/problems/arranging-coins/
# 441. Arranging Coins


class Solution:
    def arrangeCoins(self, n: int) -> int:
        def sum_gauss_method(number): # O(1)
            return (number / 2) * (number + 1) 
        
        left = 0
        right = n

        while (left <= right):
            mid = (left + right) // 2
            sum = sum_gauss_method(mid) 
            if (n < sum):
                right = mid - 1 
            elif (sum < n):
                left = mid + 1
            else:
                return mid  
        return right


class Solution2:
    def arrangeCoins(self, n: int) -> int:
        def sum_gauss_method(number): # O(1)
            return (number / 2) * (number + 1) 
        
        left = 1 
        right = n 
        res = 0

        while (left <= right):
            mid = (left + right) // 2
            sum = sum_gauss_method(mid) 
            if (n < sum):
                right = mid - 1 
            else: # sum <= n
                left = mid + 1 
                res = max(mid, res) 
        
        return res
            


