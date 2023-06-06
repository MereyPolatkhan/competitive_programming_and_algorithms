class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int n = a.size();

        int odd = 0;
        int even = 0;

        while (odd < n and even < n) {
            while (odd < n and a[odd] % 2 == 0) {
                odd++;
            }
            while (even < n and a[even] % 2 == 1) {
                even++;
            }

            if (even < n and odd < even) {
                swap(a[odd], a[even]);
                odd++;
                even++;
            }
            else if (odd > even){
                even = odd + 1;
            }
        }

        return a;
    }   
};