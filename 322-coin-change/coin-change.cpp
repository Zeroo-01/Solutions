class Solution {
public:
int helper(int ind,int a,vector<int>& coins,vector<vector<int>>&dp)
{
    if(a==0) return 0;
    if(ind==coins.size())
    {
     return -1;   
    }
    if(dp[ind][a]!=-2)return dp[ind][a];
    int nottake=helper(ind+1,a,coins,dp);
    int take=INT_MAX;
    if(coins[ind]<=a) 
    {
        int res=helper(ind,a-coins[ind],coins,dp);
        if(res!=-1) take=1+res;
    }
   if(take==INT_MAX&&nottake==-1) return dp[ind][a]=-1;
   if(take==INT_MAX) return dp[ind][a]=nottake;
   if(nottake==-1) return dp[ind][a]=take;
   return dp[ind][a]=min(take,nottake);
    

}
    int coinChange(vector<int>& coins, int amount) {

        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-2));
        return helper(0,amount,coins,dp);




    }
};