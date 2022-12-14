class Solution {
public:
    
    int countPrimes(int n) {
        if(n < 2){
            return 0;
        }
        int ans = 0;
        vector<bool> p(n + 1, true);
        for(int i = 2; i*i <= n; ++i){
            if(p[i] == true){
                for(int j = i*i; j <= n; j += i){
                    p[j] = false;
                }
            }
        }
        for(int i = 2; i < n; ++i){
            if(p[i]) ans++;
        }
        return ans;
    }
};