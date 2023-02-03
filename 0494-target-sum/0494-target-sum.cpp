class Solution {
public:

    // int ans;
    int dp[21][2023];
    int solve(vector<int> &nums, int target, int i , int val){
        
        if(i == nums.size()){
            return val == target;
        }
        
        if(dp[i][val + 1001] != -1){
            return dp[i][val + 1001];
        }
        return dp[i][val + 1001] = solve(nums, target, i+1, val+nums[i]) + solve(nums, target, i+1, val-nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(nums,target,0,0);
    }
};