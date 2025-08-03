class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256]={0};
        int m=t.size();
        for(int i=0;i<m;i++)
        {
            hash[t[i]]++;
        }
        int n=s.size();
        int sind=-1,len=INT_MAX;
        int count=0;
        int l=0,r=0;
        while(r<n)
        {
            if(hash[s[r]]>0) count++;
            hash[s[r]]--;

            while(count==m)
            {
                if(r-l+1<len)
                {
                    len=r-l+1;
                    sind=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        if(sind==-1) return "";
        return s.substr(sind,len);
        
    }
};