class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        vector<int>prev;
        for(int i=0;i<n;i++)
        {
            vector<int>curr(i+1,1);
            for(int j=1;j<i;j++)
            {
                curr[j]=prev[j-1]+prev[j];
            }
            prev=curr;
            ans.push_back(curr);
        }
        return ans;

    }
};