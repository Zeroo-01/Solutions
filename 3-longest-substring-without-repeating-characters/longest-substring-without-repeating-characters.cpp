class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<int, int> mpp;
            for(int j=i;j<n;j++)
            {
                if(mpp[s[j]]==1)  break;
                ans=max(ans,j-i+1);
                mpp[s[j]]=1;
            }
        }
        return ans;
    }
};