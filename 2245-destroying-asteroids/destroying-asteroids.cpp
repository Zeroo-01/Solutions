class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        long long x=mass;
        for(int i=0;i<n;i++)
        {
            if(x>=arr[i])
            {
                x+=arr[i];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};