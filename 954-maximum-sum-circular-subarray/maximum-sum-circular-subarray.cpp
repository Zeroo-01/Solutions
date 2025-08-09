class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int total=nums[0];
        int maxi=nums[0],currmax=nums[0],mini=nums[0],currmini=nums[0];
        for(int i=1;i<n;i++)
        {
            currmax=max(nums[i],currmax+nums[i]);
            maxi=max(maxi,currmax);
            currmini=min(nums[i],currmini+nums[i]);
            mini=min(mini,currmini);

            total+=nums[i];
        }
        if(total==mini) return maxi;
    return max(maxi,total-mini);

    }
};