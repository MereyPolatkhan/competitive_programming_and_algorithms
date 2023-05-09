def anagram(s):
    n = len(s)
    if n % 2 == 1:
        return -1

    s2 = s[:n//2]
    s1 = s[n//2:]

    dict1 = {}
    dict2 = {}

    for letter in (s1):
        if letter not in dict1:
            dict1[letter] = 1 
        else:
            dict1[letter] += 1 
    

    for letter in (s2):
        if letter not in dict2:
            dict2[letter] = 1 
        else:
            dict2[letter] += 1 
    
    d = {} 

    for key in dict1.keys():
        if key in dict2:
            d[key] = dict1[key] - dict2[key]
        else:
            if key not in d: 
                d[key] = 1
            else:
                d[key] += 1

    for key, value in d.items():
        print(key, '->', value)


anagram("abcdabxxyzabcdyb")