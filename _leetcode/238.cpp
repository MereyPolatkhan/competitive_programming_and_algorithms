class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, zeroCnt = count(begin(nums), end(nums), 0);
        if(zeroCnt > 1) return vector<int>(size(nums));               // Case-1
        for(auto c : nums) 
            if(c) prod *= c;                                          // calculate product of all elements except 0
        for(auto& c : nums)
            if(zeroCnt) c = c ? 0 : prod;                             // Case-2
            else c = prod / c;                                        // Case-3
        return nums;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);


        int cnt0 = 0;
        for (int i: nums) 
            if (i == 0)
                cnt0++;
            
        if (cnt0 > 0) {
            if (cnt0 == 1) {
                int prod = 1;
                for (int i : nums) 
                    if (i != 0) 
                        prod *= i;
                for (int i = 0; i < n; i++){
                    if (nums[i] == 0) {
                        ans[i] = prod;
                        break;
                    }
                }   
            }
            return ans;
        }


        vector<int> pref(n);
        vector<int> suff(n);
        for (int i = 0; i < n; i++) {
            pref[i] = nums[i];
            suff[i] = nums[i];
        }

        for (int i = 1; i < n; i++) {
            pref[i] *= pref[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            suff[i] *= suff[i + 1];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = (pref[i] / nums[i]) * (suff[i] / nums[i]);
        }


        return ans;
    }
};