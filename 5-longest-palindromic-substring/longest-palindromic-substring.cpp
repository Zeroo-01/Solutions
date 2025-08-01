class Solution {
public:
    bool helper(int l,int r, string &s, vector<vector<int>>&dp)
    {
        if(l>=r) return 1;
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l]==s[r]) return dp[l][r]= helper(l+1,r-1,s,dp);
        else return dp[l][r]=0;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int maxi=INT_MIN;
        int ind=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
               if(helper(i,j,s,dp))
               {
                    if(j-i+1>maxi)
                    {
                        maxi=j-i+1;
                        ind=i;
                    }

               }
            }
        }
        return s.substr(ind,maxi);
        


    }
};