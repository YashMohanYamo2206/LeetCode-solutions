class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, -1));
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        dis[0][0] = 0;
        while(!dq.empty()){
            auto curr = dq.front();
            dq.pop_front();
            for(int i = 0; i < 4; ++i){
                int r = curr.first + dx[i];
                int c = curr.second + dy[i];
                if(r < 0 || r >= n || c < 0 || c >= m || dis[r][c] != -1){
                    continue;
                }
                dis[r][c] = dis[curr.first][curr.second] + (grid[r][c] == 1);
                if(grid[r][c] == 1){
                    dq.push_back({r, c});
                }else{
                    dq.push_front({r, c});
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};