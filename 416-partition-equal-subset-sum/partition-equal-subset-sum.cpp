class Solution {
public:
    int helper(int i,int k,vector<int>& nums,vector<vector<int>>&dp)
    {
        if(k==0) return true;
        if(i==0) return nums[i]==k;
        if(dp[i][k]!=-1) return dp[i][k];
        bool nottake=helper(i-1,k,nums,dp);
        bool take=false;
        if(nums[i]<=k)
        {
            take=helper(i-1,k-nums[i],nums,dp);
        }
        return dp[i][k]=take||nottake;
        
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }  
        if(sum%2!=0) return false;      
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return helper(n-1,target,nums,dp);
    }
};