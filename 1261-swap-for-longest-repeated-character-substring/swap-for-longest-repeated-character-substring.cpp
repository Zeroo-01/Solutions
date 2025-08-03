class Solution {
public:
    int maxRepOpt1(string text) {
        int n=text.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++)
        {
            freq[text[i]-'a']++;
        }
        int  ans=0;
        for(int i=0;i<26;i++)
        {
            char ch='a'+i;
            int wrong=0;
            int l=0,r=0;
            while(r<n)
            {
                if(text[r]!=ch) wrong++;
                while(wrong>1)
                {
                    if(text[l]!=ch) wrong--;
                    l++;
                }
                int count=min(freq[ch-'a'],r-l+1);
                ans=max(ans,count);
                r++;
                
            }
            

        }
        return ans;
    }
};