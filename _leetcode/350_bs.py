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




