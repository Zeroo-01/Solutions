class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                count++;
                ans+=count;
            }
            else
            {
                count=0;
            }
        }
        return ans;

    }
};