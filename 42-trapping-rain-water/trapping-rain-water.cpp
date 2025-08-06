class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,0),right(n,0);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
  
        for(int  i=1;i<n;i++)
        {
            int j=n-1-i;
            left[i]=max(left[i-1],nums[i]);
            right[j]=max(right[j+1],nums[j]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=max(min(left[i],right[i])-nums[i],0);
        }
        return ans;
    }
};