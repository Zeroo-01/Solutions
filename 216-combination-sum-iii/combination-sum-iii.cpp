class Solution {
public:
    int sum(vector<int>&ds)
    {
        int ans=0;
        for(auto it:ds)
        {
            ans+=it;
        }
        return ans;
    }
    void helper(int k, int n,vector<vector<int>>&ans,vector<int>ds, int num)
    {
        if(k==0&&sum(ds)==n)
        {
            ans.push_back(ds);
            return;
        }
        if(num>9) return;
        ds.push_back(num);
        helper(k-1,n,ans,ds,num+1);
        ds.pop_back();
        helper(k,n,ans,ds,num+1);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;
        vector<int>ds;
        helper(k,n,ans,ds,1);
        return ans;
        

    }
};