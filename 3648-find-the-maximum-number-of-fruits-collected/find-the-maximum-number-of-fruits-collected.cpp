class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& fruits,
    vector<vector<int>>&dp)
    {
        int n=fruits.size();
        int sum=INT_MIN;
        if(i==n-1&&j==n-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i+1<n&&j-1>=0) sum=max(sum,fruits[i][j]+helper(i+1,j-1,fruits,dp));
        if(i+1<n) sum=max(sum,fruits[i][j]+ helper(i+1,j,fruits,dp));
        if(i+1<n&&j+1<n) sum=max(sum,fruits[i][j]+ helper(i+1,j+1,fruits,dp));
        return dp[i][j]=sum;
        
    }
    int helper2(int i,int j,vector<vector<int>>& fruits,
    vector<vector<int>>&dp2)
    {
        int n=fruits.size();
        int sum=INT_MIN;
        if(i==n-1&&j==n-1) return 0;
        if(dp2[i][j]!=-1) return dp2[i][j];
        if(i-1>=0&&j+1<n) sum=max(sum,fruits[i][j]+helper2(i-1,j+1,fruits,dp2));
        if(j+1<n) sum=max(sum,fruits[i][j]+ helper2(i,j+1,fruits,dp2));
        if(i+1<n&&j+1<n) sum=max(sum,fruits[i][j]+ helper2(i+1,j+1,fruits,dp2));
        return dp2[i][j]=sum;
        
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        int sum1=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
         vector<vector<int>>dp2(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            sum1+=fruits[i][i];
            fruits[i][i]=0;
        }

        int sum2=helper(0,n-1,fruits,dp);
        int sum3=helper2(n-1,0,fruits,dp2);

        return sum1+sum2+sum3;


    }
};