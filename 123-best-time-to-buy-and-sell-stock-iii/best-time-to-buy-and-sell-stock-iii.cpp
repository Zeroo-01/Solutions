class Solution {
public:
    int helper(int i,int buy,int t, vector<int>& prices,vector<vector<vector<int>>>&dp)
    {
        if(t==0) return 0;
        if(i==prices.size()) return 0;
        if(dp[i][buy][t]!=-1) return dp[i][buy][t];
        int profit=0;
        if(buy)
        {
            profit=max((-prices[i]+helper(i+1,0,t,prices,dp)),helper(i+1,1,t,prices,dp));
        }
        else
        {
            profit=max(prices[i]+helper(i+1,1,t-1,prices,dp),helper(i+1,0,t,prices,dp));
        }
        return dp[i][buy][t]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(0,1,2,prices,dp);

    }
};