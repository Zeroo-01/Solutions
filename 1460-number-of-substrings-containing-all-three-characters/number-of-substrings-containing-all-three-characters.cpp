class Solution {
public:
    int numberOfSubstrings(string arr) {
        int n=arr.size();
        unordered_map<int,int>mpp;
        int l=0,r=0;
        int ans=0;
        while(r<n)
        {
            mpp[arr[r]]++;
            while(mpp.size()==3)
            {
                ans+=(n-r);
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0)
                {
                    mpp.erase(arr[l]);
                }
                l++;
            }
            
            r++;
            

        }
        
        return ans;
    }
};