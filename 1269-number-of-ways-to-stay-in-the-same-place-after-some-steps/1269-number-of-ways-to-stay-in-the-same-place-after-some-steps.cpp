class Solution {
    int n;
    int m = 1e9+7;
    vector<vector<int>> dp;
    int dir[3] = {0, 1, -1};
    int f(int i, int k){
        if(k == 0){
            return i == 0;
        }
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        int ans = 0;
        for(auto x : dir){
            if(i + x < 0 || i + x >= n){
                continue;
            }
            ans = (ans%m + f(i + x, k - 1)%m)%m;
        }
        return dp[i][k] = ans;
    }
public:
    int numWays(int steps, int arrLen) {
        n = arrLen;
        dp.resize(steps + 1, vector<int>(steps + 1, -1));
        return f(0,steps);
    }
};