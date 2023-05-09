class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;

        int i = 0;
        int j = 0;

        while (i < firstList.size() and j < secondList.size()) {
            int frs = max(firstList[i][0], secondList[j][0]);
            int scd = min(firstList[i][1], secondList[j][1]);

            if (frs <= scd) {
                vector<int> cur;
                cur.push_back(frs);
                cur.push_back(scd);
                ans.push_back(cur);
            }

            if (firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }   
        
        return ans;
    }
};