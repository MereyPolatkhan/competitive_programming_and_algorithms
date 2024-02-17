#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <numeric>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>

#include <climits>
#include <stack>

using namespace std;
 
vector<int> lengthOfLIS(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans;
 
    ans.push_back(nums[0]);
 
    for (int i = 1; i < n; i++) {
        if (nums[i] >= ans.back()) {
            ans.push_back(nums[i]);
        }
        else {
            int low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[low] = nums[i];
        }
    }
    return ans;
}
 
// Driver program to test above function
int main()
{
    vector<int> nums = { 3 ,5 ,2 ,4 ,10, 1, 3};
    reverse(nums.begin(), nums.end());
    // Function call
    printf("Length of LIS is %d\n", lengthOfLIS(nums));
    return 0;
}
