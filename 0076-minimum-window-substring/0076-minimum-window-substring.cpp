class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }
        vector<int> freq_s(256,0), freq_t(256,0);
        int total_unique_t = 0, total_unique_s = 0;
        for(auto &c:t){
            freq_t[c]++;
            if(freq_t[c] == 1){
                total_unique_t++;
            }
        }
        // cout<<total_unique_t<<endl;
        int l = 0, L = -1, min_len = INT_MAX;
        for(int r = 0; r < s.size(); ++r){
            freq_s[s[r]]++;
            if(freq_s[s[r]] == freq_t[s[r]]){
                total_unique_s++;
            }
            if(total_unique_s == total_unique_t){
                while(freq_s[s[l]] > freq_t[s[l]]){ // keep removing s[l] till we can remove it without losing the character
                    freq_s[s[l]]--;
                    l++;
                }
                if(r - l + 1 < min_len){
                    L = l; // we only need the starting point of the string and it's length. No need to store the string itself.
                    min_len = r - l +1;
                }
            }
        }
        return (min_len != INT_MAX) ? s.substr(L, min_len) : "";
    }
};