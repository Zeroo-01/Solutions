class Solution {
public:
    // int helper(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    // {
    //     if(j==t.size()) return 1;
    //     if(i==s.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int pick=0;
    //     if(s[i]==t[j])
    //     {
    //         pick=helper(i+1,j+1,s,t,dp);  
    //     }
    //     int notpick=helper(i+1,j,s,t,dp);
    //     return dp[i][j]=pick+notpick;
    // }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][m]=1;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                double take=0;
                if(s[i]==t[j])
                {
                    take=dp[i+1][j+1];
                }
                double nottake=dp[i+1][j];
                dp[i][j]=take+nottake;
            }
        }
        return int(dp[0][0]);
        // return helper(0,0,s,t,dp);
    }
};