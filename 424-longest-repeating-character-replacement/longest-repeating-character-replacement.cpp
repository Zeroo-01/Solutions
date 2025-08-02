class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0,maxlen=0,maxfreq=0;
        int mpp[26]={0};
        while(r<n)
        {
            mpp[s[r]-'A']++;
            maxfreq=max(maxfreq,mpp[s[r]-'A']);
            while(r-l+1-maxfreq>k)
            {
                mpp[s[l]-'A']--;
                maxfreq=0;
                for(int i=0;i<25;i++)
                {
                    maxfreq=max(maxfreq,mpp[i]);
                }
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;

        }
        return maxlen;
    }
};