int mod=1e9+7;
using ll=long long;
class Solution{
public:
    int numberOfWays(int n,int x){
        vector<vector<ll>>dp(n+1,vector<ll>(n+2,0));
        for(int num=1;num<=n+1;num++)dp[0][num]=1;
        for(int rem=1;rem<=n;rem++){
            for(int num=n;num>=1;num--){
                ll power=1;
                for(int i=0;i<x;i++){
                    power*=num;
                    if(power>rem)break;
                }
                ll take=0;
                if(power<=rem)take=dp[rem-power][num+1];
                ll skip=dp[rem][num+1];
                dp[rem][num]=(take+skip)%mod;
            }
        }
        return dp[n][1];
    }
};
