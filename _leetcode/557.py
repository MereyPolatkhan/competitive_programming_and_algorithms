class Solution:
    def reverseWords(self, s: str) -> str:
        a = s.split()
        
        for i, st in enumerate(a):
            a[i] = st[::-1]
        
        return ' '.join(a)