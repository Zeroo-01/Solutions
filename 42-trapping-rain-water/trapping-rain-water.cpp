class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=0,ans=0;
        int l=0,r=n-1;
        while(l<r)
        {
            if(nums[l]<=nums[r])
            {
                if(nums[l]<left)
                {
                    ans+=left-nums[l];
                }
                left=max(left,nums[l]);
                l++;

            }
            else
            {
                if(nums[r]<right)
                {
                    ans+=right-nums[r];
                }
                right=max(right,nums[r]);
                r--;
            }
        }
        return ans;
    }
};