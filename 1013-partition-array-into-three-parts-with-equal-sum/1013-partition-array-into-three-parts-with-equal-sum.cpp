class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(begin(arr), end(arr), 0);
        int n = arr.size();
        if(sum % 3){
            return false;
        }
        int s1, s2, i1, i2;
        s1 = s2 = 0;
        for(int i = 0; i < n; ++i){
            s1 += arr[i];
            if(s1 == sum/3){
                i1 = i;
                break;
            }
        }
        
        for(int i = 0; i < arr.size() && ((n - i - 1) - i1 > 1); ++i){
            s2 += arr[n - i - 1];
            if(s2 == sum/3){
                i2 = n - i - 1;
                break;
            }
        }
        if(s1 == sum/3 && s2 == sum/3 && i2 - i1 > 1){
            return true;
        }
        return false;
    }
};