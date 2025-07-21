class Solution {
public:
    int helper(int i,int t, vector<int>& prices,vector<vector<int>>&dp)
    {
        if(i==prices.size()) return 0;
        if(t==0) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        int pro=0;
        if(t%2==0)
        {
            pro=max(-prices[i]+helper(i+1,t-1,prices,dp),helper(i+1,t,prices,dp));
        }
        else
        {
            pro=max(prices[i]+helper(i+1,t-1,prices,dp),helper(i+1,t,prices,dp));
        }
        return dp[i][t]=pro;

    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>((2*k)+1,-1));
        return helper(0,2*k,prices,dp);
    }
};