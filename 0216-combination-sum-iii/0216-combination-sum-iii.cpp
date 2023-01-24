class Solution {
    int n, k;
    vector<vector<int>> ans;
    void f(int curr, vector<int> &nums, int sum){
        if(nums.size() == k && sum == n){
            ans.push_back(nums); // accept the sequence only if we have k element and its sum is n
            return;
        }
        if(curr == 10 || nums.size() == k || sum >= n){
            return;
        }
        f(curr + 1, nums, sum); // ignore the current number
        nums.push_back(curr);
        f(curr + 1, nums, sum + curr); // choose the current number
        nums.pop_back();
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n > 45){
            return ans;
        }
        vector<int> nums;
        this->n = n;
        this->k = k;
        f(1, nums, 0);
        return ans;
    }
};