class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (vector<int> & a: image) {
            reverse(a.begin(), a.end());
        }      
        for (vector<int> & a: image) {
            for (int & x: a) {
                if (x == 0) x = 1;
                else x = 0;
            }
        }      
        return image;
    }
};