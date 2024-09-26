class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();    // row
        int n = matrix[0].size(); // 0th row's size is no of column
        vector<vector<int>> t(n, vector<int>(m));
        // store
        for (int j = 0; j <= n - 1; j++) {
            for (int i = 0; i <= m - 1; i++) {
                t[j][i] = matrix[i][j];
            }
        }
        return t;
    }
};