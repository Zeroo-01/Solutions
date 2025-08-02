class Solution {
public:
    int solve(vector<int>& nums, int goal)
    {
        int n=nums.size();
        int l=0,r=0,sum=0,ans=0;
        while(r<n)
        {
            sum+=nums[r];
           while(sum>goal)
           {
                sum-=nums[l];
                l++;
           }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal==0) return solve(nums,goal);
        return solve(nums,goal)-solve(nums,goal-1);
        


    }
};