class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp)
    {
        int n=triangle.size();
        if(i==n-1) return triangle[n-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=triangle[i][j]+helper(i+1,j,triangle,dp);
        int dig=triangle[i][j]+helper(i+1,j+1,triangle,dp);
        return dp[i][j]=min(down,dig);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
         int n=triangle.size();
         vector<vector<int>>dp(n,vector<int>(n,-1));
         dp[0][0]=triangle[0][0];
         int res=INT_MAX;
         for(int i=1;i<n;i++)
         {
            for(int j=0;j<i+1;j++)
            {
                int up= j<i ? triangle[i][j]+dp[i-1][j] : 1e6;
                int dig = j>0 ? triangle[i][j]+dp[i-1][j-1] : 1e6;
                dp[i][j]=min(up,dig);
            }
         }
         for(int j=0;j<n;j++)
         {
            res=min(res,dp[n-1][j]);
         }
        
        return res;
        //  return helper(0,0,triangle,dp);

    }
};