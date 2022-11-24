class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<int> vals;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 1; j < matrix[0].size(); ++j){
                matrix[i][j] ^= matrix[i][j - 1];
            }
        }
        for(int j = 0; j < matrix[0].size(); ++j){
            for(int i = 0; i < matrix.size(); ++i){
                if(i != 0)  
                    matrix[i][j] ^= matrix[i - 1][j];
                vals.push_back(matrix[i][j]);
            }
        }
        sort(vals.begin(), vals.end(), greater<int>());
        return vals[k - 1];
    }
};