class Solution {
public:
    // int steps(int n, vector<int>&dp)
    // {
    //     if(n==1) return 1;
    //     if(n==2) return 2;
    //     if(dp[n]!=-1) return dp[n];
    //    else return dp[n]=steps(n-1,dp)+steps(n-2,dp);
    // }
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int prev2=1;
        int prev=2;
        for(int i=3;i<=n;i++)
        {
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};