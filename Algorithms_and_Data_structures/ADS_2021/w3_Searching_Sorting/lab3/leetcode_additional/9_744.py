# https://leetcode.com/problems/find-smallest-letter-greater-than-target/
# 744. Find Smallest Letter Greater Than Target

class Solution:
    def nextGreatestLetter(self, letters: list[str], target: str) -> str:   
        if letters[-1] <= target:
            return letters[0]

        left = 0
        right = len(letters) - 1
        
        while(left <= right):
            mid = (left + right) // 2
            if (letters[mid] <= target):
                left = mid + 1 
            elif (letters[mid] > target):
                right = mid - 1            
        
        return letters[left]

letters = ["a", "b"]
target = "z"
print(Solution().nextGreatestLetter(letters, target))