class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> in(n, 0);
        for(auto &road : roads){
            in[road[0]]++;
            in[road[1]]++;
        }
        sort(in.begin(), in.end(), greater<int>());
        long long curr = n, ans = 0;
        for(int i = 0; i < n && curr; ++i, curr--){
            ans += in[i]*curr;
        }
        return ans;
    }
};