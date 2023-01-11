class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for(auto i : nums){
            pq.push(i);
        }
        while(!pq.empty() && k){
            int curr = pq.top();
            ans += curr;
            pq.pop();
            pq.push((curr + 2)/3);
            --k;
        }
        return ans;
    }
};