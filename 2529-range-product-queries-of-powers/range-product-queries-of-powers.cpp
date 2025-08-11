using ll=long long;
int mod=1e9+7;
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int m=queries.size();
        vector<int>power;
        ll ele=1;
        for(int i=0;i<32;i++)
        {
            if(n&(1<<i))
            {
                power.push_back(ele);
            }
            ele*=2;
        }
        vector<int>ans;
        for(int i=0;i<m;i++)
        {
            int x=queries[i][0];
            int y=queries[i][1];
            ll  z=1;
            for(int i=x;i<=y;i++)
            {
                z=(z*power[i])%mod;
            }
            ans.push_back(z);

        }
        return ans;
    }
};