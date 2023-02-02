class Solution {
public:

    // int ans;
    int dp[21][40010];
    int solve(vector<int> &nums, int target, int i , int val, int &cnt){
        
        if(i == nums.size()){
            if(val == target) return 1;
            return 0;
        }
        if(dp[i][val + 20001] != -1){
            return dp[i][val + 20001];
        }
        // + operation 
        dp[i][val + 20001] = solve(nums, target, i+1, val+nums[i], cnt);
        // - operation 
        dp[i][val + 20001] += solve(nums, target, i+1, val-nums[i],cnt);
        return dp[i][val + 20001];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int cnt = 0;
        memset(dp, -1, sizeof(dp));
        return solve(nums,target,0,0,cnt);
    }
};