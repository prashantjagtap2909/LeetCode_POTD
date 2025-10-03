class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        int m = height.size(), n = height[0].size();
        using T = pair<int,pair<int,int>>;
        priority_queue<T, vector<T>, greater<T>> pq; // {height, row, col}
        vector<vector<int>> vis(m, vector<int> (n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1) {
                    pq.push({height[i][j], {i, j}});
                    vis[i][j] = 1;
                }
            }
        }

        auto valid = [&](int m, int n, int r, int c){
            return (min(r,c) >= 0 && r < m && c < n);
        };
        vector<pair<int,int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int water = 0;
        while(!pq.empty()){
            auto [ht, point] = pq.top();
            auto [r, c] = point;
            pq.pop();
            for(auto[dr, dc] : dir){
                int nr = r + dr, nc = c + dc;
                if(valid(m, n, nr, nc) && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    if(height[nr][nc] < ht) water += ht - height[nr][nc];
                    pq.push({max(ht, height[nr][nc]), {nr, nc}});
                }
            }
        }

        return water;
    }
};
