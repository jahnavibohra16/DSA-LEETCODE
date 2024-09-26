class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        for (int i = 0; i <= m - 1; i++) {
            for (int j = i + 1; j <= m - 1; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i = 0; i < m; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};