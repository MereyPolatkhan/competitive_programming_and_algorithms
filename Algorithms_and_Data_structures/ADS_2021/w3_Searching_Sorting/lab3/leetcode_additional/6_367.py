# https://leetcode.com/problems/valid-perfect-square/
# 367. Valid Perfect Square

class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        
        left = 0 
        right = num 

        while(left <= right):
            mid = (left + right) // 2

            # print(f"left = {left} right = {right} mid = {mid}")       

            if (mid ** 2 == num):
                return True 
            elif (mid ** 2 < num):
                left = mid + 1
            else: # mid**2 > num
                right = mid - 1         

        return False 

s = Solution() 
print(s.isPerfectSquare(int(input())))

