# https://leetcode.com/problems/intersection-of-two-arrays/
# 349. Intersection of Two Arrays

class Solution:
    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        # len(nums1) = m --> for i in nums1 == O(m) 
        # len(nums2) = n --> def check() == O(log(n)) 
        # sorted(nums) == O(n*log(n))
        # O(n*log(n)) + O(m*log(n)) == (n + m) * log(n)
        # time complexity = (n+m)log(n) 

        # leetcode == 49 ms && 14.1 MB 

        def check(x, array):
            start = 0
            end = len(array) - 1 
            while(start <= end):
                mid = (start + end) // 2
                if (array[mid] == x):
                    return True 
                elif (array[mid] < x):
                    start = mid + 1 
                else:
                    end = mid - 1 
            
            return False 
      
        nums2 = sorted(nums2)
        s = set() 
        for i in nums1:
            if check(i, nums2) == True:
                s.add(i) 
        
        return s



class Solution2:
    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:        
        return set(nums1) & set(nums2)



