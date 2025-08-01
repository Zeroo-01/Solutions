class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=arr[i];
        }
        if(k==n)return sum;
        int l=k-1;
        int r=n-1;
        int maxsum=sum;
        while(l>=0)
        {
            sum+=arr[r];
            sum-=arr[l];
            r--;
            l--;
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};