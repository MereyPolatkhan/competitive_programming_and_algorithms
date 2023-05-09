#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() == 1 and num2.size() == 1) {
            return to_string(num1[0] + num2[0] - 2 * 48);
        }
        
        if (num1.size() < num2.size()) {
            swap(num1, num2);
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());


        string res = "";
        int remainder = 0;
        
        int i = 0;
        while (i < num2.size()) {
            int cur_sum = (num1[i] - '0') + (num2[i] - '0') + remainder;
            int n = cur_sum % 10;
            remainder = cur_sum / 10;

            res += to_string(n);
            i++;
        }

        while (i < num1.size()) {
            int cur_sum = num1[i] - '0' + remainder;
            int n = cur_sum % 10;
            remainder = cur_sum / 10;
            res += to_string(n);
            i++;    
        }

        reverse(res.begin(), res.end());
        return res;
    
    }
};

int main() {
  
    string a, b;
    cin >> a >> b;

    Solution s;
    cout << s.addStrings(a, b);


    return 0;
}