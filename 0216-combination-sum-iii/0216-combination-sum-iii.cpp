class Solution {
    int n;
    vector<vector<int>> ans;
    void f(int curr, int k, vector<int> &nums, int sum){
        if(k == 0 && sum == n){
            ans.push_back(nums);
            return;
        }
        if(curr == 10){
            return;
        }
        if(k == 0){
            return;
        }
        if(sum >= n){
            return;
        }
        f(curr + 1, k, nums, sum);
        nums.push_back(curr);
        f(curr + 1, k - 1, nums, sum + curr);
        nums.pop_back();
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n > 45){
            return ans;
        }
        vector<int> nums;
        this->n = n;
        f(1, k, nums, 0);
        return ans;
    }
};