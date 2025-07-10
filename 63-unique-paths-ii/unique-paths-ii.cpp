class Solution {
public:
int helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp)
{
    if(i==0&&j==0&&grid[i][j]==0) 
    {
        return 1;
    }
    
    if(i<0||j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(grid[i][j]==0)
    {
        int left=helper(i-1,j,grid,dp);
        int up=helper(i,j-1,grid,dp);
        return dp[i][j]=left+up;
    }
    else
    {
        dp[i][j]=0;
    }
    return dp[i][j];
}
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if (grid[0][0]==1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,grid,dp);
    }
};