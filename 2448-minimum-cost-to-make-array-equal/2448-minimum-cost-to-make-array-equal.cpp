class Solution {
    long long f(long long m, vector<int>& nums, vector<int>& cost){
        long long ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            ans += abs(m - nums[i])*cost[i];
        }
        return ans;
    }
    long long ternary_search(int l, int r, vector<int>& nums, vector<int>& cost) {
        while (r - l > 2) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            long long f1 = f(m1, nums, cost);      
            long long f2 = f(m2, nums, cost);      
            if (f1 <= f2)
                r = m2;
            else
                l = m1;
        }
        return min(f(l, nums, cost), f(l + 1, nums, cost));            
    }

public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int min = *min_element(nums.begin(), nums.end()), max = *max_element(nums.begin(), nums.end());
        long long ans = ternary_search(min, max + 1, nums, cost);
        return ans;
    }
};