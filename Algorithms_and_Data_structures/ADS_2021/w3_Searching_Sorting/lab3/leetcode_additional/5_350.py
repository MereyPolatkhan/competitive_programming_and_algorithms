# https://leetcode.com/problems/intersection-of-two-arrays-ii/
# 350. Intersection of Two Arrays II



# Time: O(min(mlogn,nlogm))
# Space: O(min(m,n))

class Solution:
    def intersect(self, nums1: list[int], nums2: list[int]) -> list[int]:
            
        # len(array) = n --> O(log(n)) 
        # in our case we accept nums2 so-> len(nums) = m --> O(log(m))
        def binary_search(array, x):
            left = 0
            right = len(array) - 1
            while(left <= right):
                mid = (left + right) // 2
                if (array[mid] == x):
                    return True 
                elif (array[mid] < x):
                    left = mid + 1
                else:
                    right = mid - 1
                
            return False

        # len(nums2) = m --> O(m*log(m))
        nums2 = sorted(nums2) 
            
        output = [] 
        
        # O(len(nums1)) = O(n)
        for element_in_1 in nums1:
            if binary_search(nums2, element_in_1) == True:
                output.append(element_in_1) 
                nums2.remove(element_in_1) 
            
        return output # O(n) * O(log(m)) + O(m*log(m)) = O((n + m)*log(m))



print(Solution().intersect([4,9,5], [9,4,9,8,4]))






# Time: O(m Log m + n Log n)
# Space: O(min(m,n)
class Solution2:
    def intersect(self, nums1: list[int], nums2: list[int]) -> list[int]:
        i = 0 # num1
        j = 0 # num2
        
        nums1.sort()
        nums2.sort()
        
        result = [] 
    
        while(True):
            if (i == len(nums1) or j == len(nums2)):
                return result

            if nums1[i] == nums2[j]:
                result.append(nums1[i])
                i += 1
                j += 1
                
            elif nums1[i] < nums2[j]:
                i += 1
            
            else:
                j += 1
        
