# https://leetcode.com/problems/sqrtx/
# 69. Sqrt(x)

class Solution:
    def mySqrt(self, x: int) -> int:
        left = 0
        right = x
        # binary search
        while(left <= right):
            mid = (left + right) // 2
            if (mid ** 2 == x):
                return mid
        
            elif (mid ** 2 < x):
                left = mid + 1
            
            elif (x < mid ** 2):
                right = mid - 1 
                
        
        return right