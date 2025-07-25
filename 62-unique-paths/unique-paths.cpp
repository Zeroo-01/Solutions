class Solution {
public:
    
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m, vector<int>(n, -1));
       dp[0][0]=1;
       
       for(int i=0;i<m;i++)
       {
        for(int j=0;j<n;j++)
        {
            if(i==0&&j==0) dp[i][j]=1;
            else{
            int left=0,right=0;
            if(i>0) left=dp[i-1][j];
            if(j>0) right=dp[i][j-1];
            dp[i][j]=left+right;
            }
        }
       }
       return dp[m-1][n-1];

    }
};