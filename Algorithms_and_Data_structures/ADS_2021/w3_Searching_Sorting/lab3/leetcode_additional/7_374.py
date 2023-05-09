# https://leetcode.com/problems/guess-number-higher-or-lower/
# 374. Guess Number Higher or Lower
class Solution:
    def guessNumber(self, n: int) -> int:
        start = 1
        end = n 
        
        while(start <= end):
            mid = (start + end) // 2
            
            if (guess(mid) == 0):
                return mid
            
            elif (guess(mid) == -1):
                end = mid - 1
            
            else:
                start = mid + 1 
                