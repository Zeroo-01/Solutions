class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& arr) {
        int n=arr.size();
        int maxi=0;
        int maxd=0;
        for(int i=0;i<n;i++)
        {
            int x=arr[i][0];
            int y=arr[i][1];
            int d=x*x+y*y;
            if(d>maxd)
            {
                maxd=d;
                maxi=x*y;
            }
            else if(d==maxd)
            {
                maxi=max(maxi,x*y);
            }

        }
        return maxi;
    }
};