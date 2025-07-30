using ll=long long;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ll n=nums.size();
      ll maxi=nums[0];
      ll ans=1;
      ll curr=1;
      for(int i=1;i<n;i++)
      {
        if(nums[i]==maxi)
        {
            curr++;
            ans=max(ans,curr);
        }
        else if(nums[i]>maxi)
        {
            curr=1;
            ans=1;
            maxi=nums[i];
        }
        else
        {
            curr=0;
            
        }
      }
      return int(ans);
        
    }
};