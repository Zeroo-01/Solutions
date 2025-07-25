class Solution {
public:
    // int helper(int i,int buy,int t, vector<int>& prices,vector<vector<vector<int>>>&dp)
    // {
    //     if(t==0) return 0;
    //     if(i==prices.size()) return 0;
    //     if(dp[i][buy][t]!=-1) return dp[i][buy][t];
    //     int profit=0;
    //     if(buy)
    //     {
    //         profit=max((-prices[i]+helper(i+1,0,t,prices,dp)),helper(i+1,1,t,prices,dp));
    //     }
    //     else
    //     {
    //         profit=max(prices[i]+helper(i+1,1,t-1,prices,dp),helper(i+1,0,t,prices,dp));
    //     }
    //     return dp[i][buy][t]=profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>after(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                for(int t=1;t<=2;t++)
                {
                    if(j)
                        {
                            curr[j][t]=max(-prices[i]+after[0][t],after[1][t]);
                        }
                        else
                        {
                            curr[j][t]=max(prices[i]+after[1][t-1],after[0][t]);
                        }
                }
                
            }
            after=curr;
        }
        return after[1][2];
        // return helper(0,1,2,prices,dp);

    }
};