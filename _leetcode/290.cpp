class Solution:
    def func1(self, pattern, s) -> bool:
        a = s.split()
        if (len(pattern) != len(a)):
            return False

        d = dict()
        for i, letter in enumerate(pattern):
            if (letter not in d): 
                d[letter] = a[i]
            else:
                if (d[letter] != a[i]):
                    return False
        
        return True

    def func2(self, s, pattern) -> bool:
        a = s.split()
        if (len(pattern) != len(a)):
            return False

        d = dict()
        for i, word in enumerate(a):
            if (word not in d): 
                d[word] = pattern[i]
            else:
                if (d[word] != pattern[i]):
                    # print(d[word], pattern[i])
                    return False
        
        return True


    def wordPattern(self, pattern: str, s: str) -> bool:
        return self.func1(pattern, s) and self.func2(s, pattern)
        