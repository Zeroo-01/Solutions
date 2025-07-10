class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& matrix, vector<vector<int>>&dp)
    {
        int n=matrix.size();
        if(j<0||j>n-1) return 1e6;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1e9) return dp[i][j];
        int left=matrix[i][j]+helper(i-1,j-1,matrix,dp);
        int up = matrix[i][j]+helper(i-1,j,matrix, dp);
        int right = matrix[i][j]+helper(i-1,j+1,matrix,dp);

        return dp[i][j] = min({left, up, right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1e9));
        int ans=1e6;
        for(int j=0;j<n;j++)
        {
           int x= helper(n-1,j,matrix,dp);
            ans=min(ans,x);
        }
        return ans;
        
    }
};