class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end(),[](vector<int>& a,vector<int>& b)
        {
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });


        vector<int>temp;
        temp.push_back(arr[0][1]);
        for(int i=1;i<n;i++)
        {
            if(arr[i][1]>temp.back())
            {
                temp.push_back(arr[i][1]);
            }
            else
            {
                int j=lower_bound(temp.begin(),temp.end(),arr[i][1])-temp.begin();
                temp[j]=arr[i][1];
            }
        }
        return temp.size();
    }
};