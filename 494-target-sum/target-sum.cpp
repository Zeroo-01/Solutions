class Solution {
public:
int helper(int i,int t,vector<int>& nums,vector<vector<int>>&dp,int total)
{
    if (i == nums.size()) return t == 0 ? 1 : 0;
    if((t+total<0)||t+total>2*total) return 0;
    if(dp[i][t+total]!=-1) return dp[i][t+total];
    int plus=helper(i+1,t-nums[i],nums,dp,total);
    int minus=helper(i+1,t+nums[i],nums,dp,total);
    return dp[i][t+total]=plus+minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));
        return helper(0,target,nums,dp,total);
    }
};