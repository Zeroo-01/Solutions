class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
            int n=nums.size();
            int l=0,r=0;
            int ans=0;
            while(r<n)
            {
                if(nums[r]!=1)
                {
                    if(k>0)
                    {
                        k--;
                        ans=max(ans,r-l+1);
                    }
                    else
                    {
                        while(nums[l]!=0)
                        {
                            l++;
                        }
                        l++;
                    }
                
                }
                else
                {
                    ans=max(ans,r-l+1);
                }
                r++;
            }
            return ans;
    }
};