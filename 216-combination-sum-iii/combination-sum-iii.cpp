class Solution {
public:
    void helper(int k, int n, vector<vector<int>>& ans, vector<int>& ds, int num, int sum) {
        if (k == 0) {
            if (sum == n)
                ans.push_back(ds);
            return;
        }
        if (num > 9) return;

        ds.push_back(num);
        helper(k - 1, n, ans, ds, num + 1, sum + num);
        ds.pop_back();

        helper(k, n, ans, ds, num + 1, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(k, n, ans, ds, 1, 0);
        return ans;
    }
};
