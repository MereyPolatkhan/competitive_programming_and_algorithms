#include <iostream> 
#include <algorithm> 

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
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
        if (remainder > 0) res += to_string(remainder);
        reverse(res.begin(), res.end());
        return res;
    
    }
};

class Solution {
public:
    int f(char c) {
        return int(c) - 48;
    }

    string fill_with_zero(string s, int n) {
        for (int i = 0; i < n; i++) {
            s += '0';
        }
        return s;
    }

    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        if (num1.size() > num2.size()) {
            num2 = fill_with_zero(num2, num1.size()-num2.size());
        }
        if (num2.size() > num1.size()) {
            num1 = fill_with_zero(num1, num2.size()-num1.size());
        }

        int n = num1.size(); // num2.size()
        int carry = 0; 
        string result;
        int sum; 
        for (int i = 0; i < n; i++) {
            sum = carry + f(num1[i]) + f(num2[i]);
            result += to_string(sum % 10);
            carry = sum / 10;
        }
        // cout << "carry=" << carry << endl;
        if (carry != 0) result += to_string(carry);
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {

    Solution s;
    string num1; cin >> num1;
    string num2; cin >> num2;

    cout << s.addStrings(num1, num2);

    return 0;
}