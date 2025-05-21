class Solution {
public:
    void combinations(int index, vector<int>& arr, int t, vector<vector<int>>& ans, vector<int>& ls) {
        if (t == 0) {
            ans.push_back(ls);
            return;
        }
        for (int i = index; i < arr.size(); ++i) {

            if (i > index && arr[i] == arr[i - 1]) continue;

            if (arr[i] > t) break;

            ls.push_back(arr[i]);
            combinations(i + 1, arr, t - arr[i], ans, ls);
            ls.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int t) {
        sort(arr.begin(), arr.end()); 
        vector<vector<int>> ans;
        vector<int> ls;
        combinations(0, arr, t, ans, ls);
        return ans;
    }
};
