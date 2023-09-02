// assabiyah

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        map<char, int> mp;
        int l = 0;
        int res = 0;
        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};

class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int n = s.length();
        if (k >= n) {
            return n;
        }
        
        int left = k, right = n;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            
            if (isValid(s, mid, k)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
    
    private boolean isValid(String s, int size, int k) {
        int n = s.length();
        Map<Character, Integer> counter = new HashMap<>();
        
        for (int i = 0; i < size; i++) {
            char c = s.charAt(i);
            counter.put(c, counter.getOrDefault(c, 0) + 1);
        }
        
        if (counter.size() <= k) {
            return true;
        }
        
        for (int i = size; i < n; i++) {
            char c1 = s.charAt(i);
            counter.put(c1, counter.getOrDefault(c1, 0) + 1);
            char c2 = s.charAt(i - size);
            counter.put(c2, counter.getOrDefault(c2, 0) - 1);
            if (counter.get(c2) == 0) {
                counter.remove(c2);
            }
            if (counter.size() <= k) {
                return true;
            }
        }
        
        return false;
    }
}

class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int n = s.length();
        int maxSize = 0;
        Map<Character, Integer> counter = new HashMap<>();
        
        int left = 0;
        for (int right = 0; right < n; right++) {
            counter.put(s.charAt(right), counter.getOrDefault(s.charAt(right), 0) + 1);
            
            while (counter.size() > k) {
                counter.put(s.charAt(left), counter.get(s.charAt(left)) - 1);
                if (counter.get(s.charAt(left)) == 0) {
                    counter.remove(s.charAt(left));
                }
                left++;
            }
            
            maxSize = Math.max(maxSize, right - left + 1);
        }
                    
        return maxSize;  
    }
}


class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int n = s.length();
        int maxSize = 0;
        Map<Character, Integer> counter = new HashMap<>();
        
        for (int right = 0; right < n; right++) {
            counter.put(s.charAt(right), counter.getOrDefault(s.charAt(right), 0) + 1);
            
            if (counter.size() <= k) {
                maxSize++;
            } else {
                counter.put(s.charAt(right - maxSize), counter.get(s.charAt(right - maxSize)) - 1);
                if (counter.get(s.charAt(right - maxSize)) == 0) {
                    counter.remove(s.charAt(right - maxSize));
                }
            }
        }

        return maxSize; 
    }
}