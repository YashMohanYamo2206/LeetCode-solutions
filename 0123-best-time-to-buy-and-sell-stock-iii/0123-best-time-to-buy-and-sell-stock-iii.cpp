class Solution {
    // vector<ve
    int dp[100001][5];
    int f(int idx, int transactionDone, vector<int>& prices){
        if(transactionDone == 4 || idx == prices.size()){
            return (transactionDone == 2) || (transactionDone == 4)  ? 0 : INT_MIN/10; //if transactions done then return 0, else return a big -ve value as invalid answer.
        }
        if(dp[idx][transactionDone] != -1){
            return dp[idx][transactionDone];  
        }
        int maxCurrProfit = 0;
        //choices
        maxCurrProfit = max(maxCurrProfit, f(idx + 1, transactionDone, prices)); // don't buy or sell stock
        if(transactionDone == 0 || transactionDone == 2){
            maxCurrProfit = max(maxCurrProfit, 
                                -prices[idx] + f(idx + 1, transactionDone + 1, prices)); // buy the stock.
        }else{
            maxCurrProfit = max(maxCurrProfit, 
                                prices[idx] + f(idx + 1, transactionDone + 1, prices)); // sell the stock.
        }
        return dp[idx][transactionDone] = maxCurrProfit;
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, prices);
    }
};