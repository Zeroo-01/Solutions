class Solution {
public:
    int helper(int i,int a,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(a==0) return 1;
        if(i==coins.size()) return 0;
        if(dp[i][a]!=-1) return dp[i][a];
        int notpick=helper(i+1,a,coins,dp);
        int take=0;
        if(coins[i]<=a) take=helper(i,a-coins[i],coins,dp);
        return dp[i][a]=take+notpick;

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(0,amount,coins,dp);

    }
};