class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        multiset<int, greater<int>> pq;
        for(auto i : nums){
            pq.insert(i);
        }
        while(!pq.empty() && k){
            int curr = *pq.begin();
            ans += curr;
            pq.erase(pq.begin());
            pq.insert((curr + 2)/3);
            --k;
        }
        return ans;
    }
};