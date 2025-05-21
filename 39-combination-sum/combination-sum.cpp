class Solution {
public:
    void combinations(int index,vector<int>& arr, int t, vector<vector<int>>& ans,vector<int>& ls)
    {
        if(index==arr.size())
        {
            if(t==0)
            {
                ans.push_back(ls);
            }
            return;
        }
        if(arr[index]<=t)
        {
            ls.push_back(arr[index]);
            combinations(index,arr,t-arr[index],ans,ls);
            ls.pop_back();
        }
        combinations(index+1,arr,t,ans,ls);
    
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int t) {
         vector<vector<int>>ans;
         vector<int>ls;
         combinations(0,arr,t,ans,ls);
        return ans;
        
    }
};