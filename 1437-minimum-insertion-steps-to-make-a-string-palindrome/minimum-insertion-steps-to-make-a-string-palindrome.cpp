class Solution {
public:
    int minInsertions(string s) {
        string text1=s;
        string text2=s;
        reverse(text2.begin(),text2.end());

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
        return n-prev[0];
    }
};