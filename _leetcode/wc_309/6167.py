class Solution:
    def checkDistances(self, s: str, distance: list[int]) -> bool:
        hashmap = {}
        for i in range(len(s)):
            for j in range(i + 1, len(s)):
                if s[i] == s[j]:
                    hashmap[s[i]] = j - i - 1 
        
        for i, v in hashmap.items():
            if v != distance[ord(i) - 97]:  
                return False 
        
        return True
