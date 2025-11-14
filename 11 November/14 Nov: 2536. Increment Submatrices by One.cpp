class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int m = queries.size();
        for (int k = 0; k < m; k++) {
            int row1 = queries[k][0];
            int col1 = queries[k][1];
            int row2 = queries[k][2];
            int col2 = queries[k][3];
            for (int r = row1; r <= row2; r++) {
                for (int c = col1; c <= col2; c++) {
                    v[r][c]++;
                }
            }
        }
        return v;
    }
};
