class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int>st;
        int n=nums.size();
        int ans=0;
        int curr=0;
        int l=0,r=0;
        while(r<n)
        {
            if(st.find(nums[r])==st.end())
            {
                st.insert(nums[r]);
                curr+=nums[r];
                ans=max(ans,curr);
                r++;
            }
            else
            {
                st.erase(nums[l]);
                curr-=nums[l];
                l++;
            }
            
        }
        return ans;
    }
};