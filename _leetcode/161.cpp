// author: @assabiyah

class Solution {
public:
    bool isOneEditDistance(string &s, string &t) {
        if (abs((int)s.size() - (int)t.size()) >= 2) {
            return false;
        }
        if (s.size() > t.size()) {
            return isOneEditDistance(t, s);
        }

        int i = 0;
        int j = 0;

        while (i < s.size() and j < t.size()) {
            if (s[i] == t[j]) {
                i++; j++;
            }
            else {
                if (s.size() < t.size()) {
                    j++;
                }
                else {
                    i++; j++;
                }
                return s.substr(i) == t.substr(j);
            }
        }
        return s.size() == t.size() - 1;
    }
};

class Solution {
  public boolean isOneEditDistance(String s, String t) {
    int ns = s.length();
    int nt = t.length();

    // Ensure that s is shorter than t.
    if (ns > nt)
      return isOneEditDistance(t, s);

    // The strings are NOT one edit away distance  
    // if the length diff is more than 1.
    if (nt - ns > 1)
      return false;

    for (int i = 0; i < ns; i++)
      if (s.charAt(i) != t.charAt(i))
        // if strings have the same length
        if (ns == nt)
          return s.substring(i + 1).equals(t.substring(i + 1));
        // if strings have different lengths
        else
          return s.substring(i).equals(t.substring(i + 1));

    // If there is no diffs on ns distance
    // the strings are one edit away only if
    // t has one more character. 
    return (ns + 1 == nt);
  }
}