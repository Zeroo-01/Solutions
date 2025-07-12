class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
    vector<int> delta(2 * limit + 2, 0);

    for (int i = 0; i < n / 2; ++i) {
        int a = nums[i];
        int b = nums[n - 1 - i];

        int low = min(a, b) + 1;
        int high = max(a, b) + limit;
        int sum = a + b;

        delta[2] += 2;
        delta[low] -= 1;
        delta[sum] -= 1;
        delta[sum + 1] += 1;
        delta[high + 1] += 1;
    }

    int ans = INT_MAX;
    int curr = 0;
    for (int i = 2; i <= 2 * limit; ++i) {
        curr += delta[i];
        ans = min(ans, curr);
    }

    return ans;
    }
};