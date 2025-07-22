class Solution {
public:
// int helper(int i,int prev,vector<int>&nums,vector<vector<int>>&dp)
// {
//     if(i==nums.size()) return 0;
//     if(dp[i][prev+1]!=-1) return dp[i][prev+1];
//     int nottake=helper(i+1,prev,nums,dp);
//     int take=0;
//     if(prev==-1||nums[i]>nums[prev])
//     {
//         take=1+helper(i+1,i,nums,dp);
//     }
//     return dp[i][prev+1]=max(take,nottake);
// }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return helper(0,-1,nums,dp);
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i])
                {
                    dp[i]=max(dp[i],1+dp[prev]);
                    maxi=max(dp[i],maxi);
                }
                
            }
        }
        return maxi;
        
    }
};