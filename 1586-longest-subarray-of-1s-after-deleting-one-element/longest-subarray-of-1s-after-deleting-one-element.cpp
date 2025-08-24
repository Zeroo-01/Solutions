class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int count=0;
        int maxi=0;
        while(r<n)
        {
            if(nums[r]==0)
            {
                count++;
            }
            while(count>1)
            {
                if(nums[l]==0)
                {
                    count--;
                }
                 l++;
            }
            maxi=max(maxi,r-l);
            r++;
        }

        return maxi;
    }
};