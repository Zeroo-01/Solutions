class Solution {
public:
int helper(int i1,int i2,string &text1, string &text2, vector<vector<int>>&dp)
{
    if(i1==text1.size()||i2==text2.size()) return 0;
    if(dp[i1][i2]!=-1) return dp[i1][i2];
    int pick=0;
    if(text1[i1]==text2[i2])
    {
        pick=1+helper(i1+1,i2+1,text1,text2,dp);
    }
    int notpick=  max(helper(i1+1,i2,text1,text2,dp),helper(i1,i2+1,text1,text2,dp));
    return dp[i1][i2]=max(pick,notpick);


}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,text1,text2,dp);

    }
};