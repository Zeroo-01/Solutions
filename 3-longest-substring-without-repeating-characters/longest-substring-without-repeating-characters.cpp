class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0;
        unordered_map<char, int> mpp;
        int l=0,r=0;
        while(r<n)
        {
            if(mpp.count(s[r])!=0&& mpp[s[r]] >= l)
            {
                l=mpp[s[r]]+1;
            }
            
            mpp[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
            
        }
            
        return ans;
    }
};