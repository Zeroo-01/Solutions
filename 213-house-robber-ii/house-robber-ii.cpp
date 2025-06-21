class Solution {
public:
int helper(int ind,vector<int>& nums,vector<int>&dp,int start)
{
    if(ind<start) return 0;
    if(dp[ind]!=-1) return dp[ind];
    if(ind==start) return nums[start];
    int pick=nums[ind]+helper(ind-2,nums,dp,start);
    int noti=helper(ind-1,nums,dp,start);
    return dp[ind]=max(pick,noti);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return max(helper(n-2,nums,dp1,0),helper(n-1,nums,dp2,1));
    }
};