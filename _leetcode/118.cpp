// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
// Memory Usage: 6.5 MB, less than 71.41% of C++ online submissions for Pascal's Triangle.


#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > res(1);

        res[0].push_back(1);


        for (int i = 2; i <= numRows; i++) {
            
            vector<int> last = res[res.size() - 1];
            vector<int> temp(last.size() + 2);
            
            for (int k = 0; k < temp.size() - 2; k++) {
                temp[k + 1] = last[k];
            }

            vector<int> row;
            
            for (int j = 0; j < i; j++) {
                row.push_back(temp[j] + temp[j + 1]);
            }
            res.push_back(row);
        }

        return res;
    }
};
 

int main() {

    Solution s;

    int n; cin >> n;

    vector<vector<int>> res = s.generate(n);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}