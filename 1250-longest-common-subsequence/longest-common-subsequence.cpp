class Solution {
public:
// int helper(int i1,int i2,string &text1, string &text2, vector<vector<int>>&dp)
// {
//     if(i1==text1.size()||i2==text2.size()) return 0;
//     if(dp[i1][i2]!=-1) return dp[i1][i2];
//     int pick=0;
//     if(text1[i1]==text2[i2])
//     {
//         pick=1+helper(i1+1,i2+1,text1,text2,dp);
//     }
//     int notpick=  max(helper(i1+1,i2,text1,text2,dp),helper(i1,i2+1,text1,text2,dp));
//     return dp[i1][i2]=max(pick,notpick);


// }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int pick=0;
                if(text1[i]==text2[j]) pick=1+prev[j+1];
                int notpick=max(prev[j],curr[j+1]);
                curr[j]=max(pick,notpick);
            }
            prev=curr;
        }
        return prev[0];
        



        //return helper(0,0,text1,text2,dp);

    }
};