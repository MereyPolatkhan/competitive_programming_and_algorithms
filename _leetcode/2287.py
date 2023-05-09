class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        hashmap = dict()
        a = []
        for i in s:
            if i not in hashmap:
                hashmap[i] = 1
            else:
                hashmap[i] += 1

        for i in target:
            a.append(hashmap[i])
        
        return min(a) // len(target)


s = Solution()
print(s.rearrangeCharacters("abbaccaddaeea", "aaaaa"))