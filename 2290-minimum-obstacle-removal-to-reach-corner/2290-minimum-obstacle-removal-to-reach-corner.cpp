class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        dis[0][0] = 0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            for(int i = 0; i < 4; ++i){
                int r = curr.second.first + dx[i];
                int c = curr.second.second + dy[i];
                if(r < 0 || r >= n || c < 0 || c >= m){
                    continue;
                }
                if(dis[r][c] > dis[curr.second.first][curr.second.second] + grid[r][c]){
                    dis[r][c] = dis[curr.second.first][curr.second.second]+ grid[r][c];
                    pq.push({dis[r][c], {r, c}});
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};