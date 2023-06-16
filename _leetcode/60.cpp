class Solution {
public:

    void fill_fac(vector<int> & fac, int n) {
        fac[0] = 1;
        int factorial = 1;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
            fac[i] = factorial;
        }
    }

    void fill_digits(vector<int> & digits, int n) {
        for (int i = 0; i < digits.size(); i++) {
            digits[i] = i + 1;
        }
    }

    void func(vector<int> & res, vector<int> & digits, vector<int> & fac, int n, int k) {
        if (n == 1) {
            res.push_back(digits[0]);
        
            return;
        }
        int index = k / (fac[n - 1]);
        if (k % (fac[n - 1]) == 0) {
            index--;
        }
        res.push_back(digits[index]);
        digits.erase(digits.begin() + index);
        k -= (fac[n - 1] * index);
        n--;
        func(res, digits, fac, n, k);
    }

    vector<int> get_perm(int n, int k) {
        vector<int> res;
        vector<int> digits(n);
        vector<int> fac(n + 1);
        fill_fac(fac, n);
        fill_digits(digits, n);
        func(res, digits, fac, n, k);



        return res;
    }

    string getPermutation(int n, int k) {
        vector<int> a = get_perm(n, k);
        string res = "";
        for (int i : a) {
            res += to_string(i);
        }
        return res;
    }
};