class Solution {
    int ans;
    int dfs(int curr, vector<vector<int>> &adj, string &s){
        vector<int> pathLengths;
        for(auto child : adj[curr]){
            if(s[curr] != s[child]){
                pathLengths.push_back(1 + dfs(child, adj, s));
            }else{
                ans = max(ans, dfs(child, adj, s));
            }
        }
        if(pathLengths.size() == 0){
            return 0;
        }
        if(pathLengths.size() > 1){
            sort(pathLengths.begin(), pathLengths.end(), greater<int>());
            ans = max(ans, pathLengths[0] + pathLengths[1]);
        }
        return pathLengths[0];
    }
public:
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> adj(parent.size());
        vector<int> vis(parent.size(), 0);
        for(int i = 1; i < parent.size(); ++i){
            adj[parent[i]].push_back(i);
        }
        ans = 0;
        ans = max(ans, dfs(0, adj, s));
        return ans + 1;
    }
};