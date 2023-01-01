class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int> p(1500, 1);
        for(int i = 2; i*i <= 1000; ++i){
            if(p[i]){
                for(int j = i*i; j <= 1000; j += i){
                    p[j] = 0;
                }
            }
        }
        vector<int> primes;
        for(int i = 2; i <= 1000; ++i){
            if(p[i]){
                primes.push_back(i);
            }
        }
        set<int> ans;
        for(auto num : nums){
            for(auto i : primes){
                if(num % i == 0){
                    // cout << i << endl;
                    ans.insert(i);
                    while(num && num%i == 0){
                        num /= i;
                    }
                }
            }
        }
        return ans.size();
    }
};