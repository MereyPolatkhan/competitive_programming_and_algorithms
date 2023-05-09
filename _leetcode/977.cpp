class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int lsq = nums[l] * nums[l];
            int rsq = nums[r] * nums[r];
            if (lsq < rsq) {
                ans.push_back(rsq);
                r--;
            }
            else {
                ans.push_back(lsq);
                l++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> ans;
    int l;
    int r;  

    void bin_search(vector<int> & nums) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == 0) {
                l = mid;
                r = mid;
                return;
            }
            else if (nums[mid] < 0) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        swap(l, r);
    }

    vector<int> sortedSquares(vector<int>& nums) {
        l = 0;
        r = nums.size() - 1;
        bin_search(nums);
        // cout << l << " " << r << "\n";
        if (l == r) {
            ans.push_back(nums[l]);
            l--;
            r++;
        }
        // cout << l << " " << r << "\n";
        while (l >= 0 and r < nums.size()) {
            int lsq = nums[l] * nums[l];
            int rsq = nums[r] * nums[r];

            if (lsq < rsq) {
                ans.push_back(lsq);
                l--;
            }
            else {
                ans.push_back(rsq);
                r++;
            }
        }

        while (l >= 0) {
            int lsq = nums[l] * nums[l];
            ans.push_back(lsq);
            l--;
        }

        while (r < nums.size()) {
            int rsq = nums[r] * nums[r];
            ans.push_back(rsq);
            r++;
        }
    
        return ans;
    }
};



// [-7,-3,2,3,11]
//   0  1 2 3 4
//        l     
//      r
//      m