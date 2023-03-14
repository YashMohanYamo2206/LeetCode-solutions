class Solution {
    vector<int> dp;
    int f(int day, set<int> &days, vector<int>& costs){
        if(day > 365){
            return 0;
        }
        if(dp[day] != -1){
            return dp[day];
        }
        int ans;
        if(days.find(day) != days.end()){
            ans = min({costs[0] + f(day + 1, days, costs), costs[1] + f(day + 7, days, costs), costs[2] + f(day + 30, days, costs)});
        }else{
            ans = f(day + 1, days, costs);
        }
        return dp[day] = ans;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        set<int> _days(days.begin(), days.end());
        dp.resize(366, -1);
        return f(0, _days, costs);   
    }
};