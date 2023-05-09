class Solution:
    def numTrees(self, n: int) -> int:
        
        arr = [1] * (n + 1)
        for nodes in range(2, n + 1):
            summ = 0
            for root in range(1, nodes + 1):
                left = root - 1 
                right = nodes - root 
                summ = summ + (arr[left] * arr[right])
            arr[nodes] = summ 
        
        return arr[n]