class Solution {
public:
// int helper(int i,int buy,vector<int>& prices, vector<vector<int>>&dp)
// {
//     if(i==prices.size()) return 0;
//     if(dp[i][buy]!=-1) return dp[i][buy];
//     int pro=0;
//     if(buy)
//     {

//        pro= max(helper(i+1,0,prices,dp)-prices[i],helper(i+1,1,prices,dp));
//     }
//     else
//     {
    
//         pro=max(helper(i+1,0,prices,dp),prices[i]+helper(i+1,1,prices,dp));
//     }
//     return dp[i][buy]=pro;
// }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j>=0;j--)
            {
                if(j==1)
                {
                    dp[i][j]=max(dp[i+1][0]-prices[i],dp[i+1][1]);
                }
                else
                {
                   dp[i][j]= max(dp[i+1][0],prices[i]+dp[i+1][1]);
                }
            }
        }
        return dp[0][1];
        //return helper(0,1,prices,dp);
    }
};