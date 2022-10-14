class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int, greater<int>> ms;
        for(int i = 0; i < k; ++i){
            ms.insert(nums[i]);
        }
        vector<int> ans;
        ans.push_back(*ms.begin());
        for(int i = k; i < nums.size(); ++i){
            ms.insert(nums[i]);
            ms.erase(ms.find(nums[i - k]));
            ans.push_back(*ms.begin());
        }
        return ans;
    }
};