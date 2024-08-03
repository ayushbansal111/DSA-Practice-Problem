class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int count = 0;
        int total = row * col;
        int strow = 0;
        int stcol = 0;
        int endrow = row - 1;
        int endcol = col - 1;
        while (count < total) {
            // first row
            for (int i = stcol; count < total && i <= endcol; i++) {
                ans.push_back(matrix[strow][i]);
                count++;
            }
            strow++;
            // last coloumn
            for (int i = strow; count < total && i <= endrow; i++) {
                ans.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;
            // last row
            for (int i = endcol; count < total && i >= stcol; i--) {
                ans.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;
            // first coloumn
            for (int i = endrow; count < total && i >= strow; i--) {
                ans.push_back(matrix[i][stcol]);
                count++;
            }
            stcol++;
        }
        return ans;
    }
};