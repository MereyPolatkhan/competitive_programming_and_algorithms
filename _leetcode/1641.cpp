class Solution {
public:
    int countVowelStrings(int n) {
        int a[5] = {1, 1, 1, 1, 1};
        for (int i = 1; i < n; i++) {
            for (int j = 3; j >= 0; j--) {
                a[j] = a[j] + a[j + 1];
            }
        }      
        
        int s = 0;
        for (int i = 0; i < 5; i++) {
            s += a[i];
        } 
        
        return s;
    }
};
class Solution {
public:
    int countVowelStrings(int n) {
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int j = 1; j < n; j++) {
            o = o + u;
            i = i + o;
            e = e + i;
            a = a + e;
        }
        
        return a + e + i + o + u;
    }
};



class Solution {
public:
    int countVowelStrings(int n) {
        int a[5] = {1, 1, 1, 1, 1};
        int sum = 5;
        for (int i = 2; i <= n; i++) {
            int row[5];
            for (int j = 0; j < 5; j++) {
                if (j == 0) {
                    row[j] = sum;
                } 
                else {
                    row[j] = row[j - 1] - a[j - 1];
                }
            }
            sum = 0;
            for (int j = 0; j < 5; j++) {
                a[j] = row[j];
                sum += a[j];
            }

        }
        return sum;
    }
};