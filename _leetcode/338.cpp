class Solution {
public: 
    vector<int> countBits(int n) {
        vector<int> d(n + 1);

        int offset = pow(2, 0); // offset = 1
        
        for (int i = 1; i <= n; i++) {
            if (offset * 2 == i) {
                offset = i;
            }

            d[i] = 1 + d[i - offset];
        }

        return d;
    }
};


class Solution {
public:
    vector<int> res;

    string n_to_bits(int n) { // n logn
        string s;
        while (n != 0) {
            s += to_string(n % 2);
            n = n / 2;
        }
        reverse(s.begin(), s.end());
    
        return s;
    }

    int counter(string s) { // n
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                k++;
            }
        }

        return k;
    }

    vector<int> countBits(int n) {
        for (int i = 0; i <= n; i++) {
            res.push_back(counter(n_to_bits(i))); //  n * logn 
        }

        return res;
    }
};
    
