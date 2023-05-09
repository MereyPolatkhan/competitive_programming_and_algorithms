class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex + 1;

        vector<int> res;
        res.push_back(1);

        for (int i = 2; i <= n; i++) {
            vector<int> extra(res.size() + 2);
            for (int j = 0; j < extra.size() - 2; j++) {
                extra[j + 1] = res[j];
            }
            res.clear();
            for (int j = 0; j < extra.size() - 1; j++) {
                res.push_back(extra[j] + extra[j + 1]);
            }
        }
    return res;
    }
};

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex + 1;
        vector<vector<int>> res(1);
        
        res[0].push_back(1);

        for (int i = 2; i <= n; i++) {
            vector<int> last_vector = res[res.size() - 1];
            vector<int> temp(last_vector.size() + 2);

            for (int k = 0; k < temp.size() - 2; k++) 
                temp[k + 1] = last_vector[k];

            vector<int> row;
            
            for (int j = 0; j <= last_vector.size(); j++) 
                row.push_back(temp[j] + temp[j + 1]); 

            res.push_back(row);
        }

        return res[rowIndex];
    }
};