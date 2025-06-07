class Solution {
public:
void helper(int index,vector<int>& nums,set<vector<int>>&ans,vector<int>&ds)
{
    if(index==nums.size())
    {
        ans.insert(ds);
        return;
    }
    ds.push_back(nums[index]);
    helper(index+1,nums,ans,ds);
    ds.pop_back();
    helper(index+1,nums,ans,ds);


}
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>ds;
        // ans.insert();
        helper(0,nums,ans,ds);
        vector<vector<int>>ansr(ans.begin(),ans.end());
        return ansr;
    }
};