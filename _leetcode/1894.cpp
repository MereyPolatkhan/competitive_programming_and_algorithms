class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for (auto i: chalk) sum += i;
        
        k = k % sum;
        int res = 0;
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                res = i;
                break;
            }
            k = k - chalk[i];
        }
        return res;
    }
};