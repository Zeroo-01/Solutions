class Solution {
public:
    int maxSatisfied(vector<int>& arr, vector<int>& grumpy, int k) {
        int n=arr.size();
        int sum0=0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
            {
                sum0+=arr[i];
            }
        }
        int sum1=0;
        for(int i=0;i<k;i++)
        {
            if(grumpy[i]==1)
            {
                sum1+=arr[i];
            }
        }
        int maxi=sum1;
        for(int i=k;i<n;i++)
        {
            if(grumpy[i]==1)
            {
                sum1+=arr[i];
            }
            if(grumpy[i-k]==1)
            {
                sum1-=arr[i-k];
            }
            maxi=max(maxi,sum1);
        }
        maxi+=sum0;
        
        return maxi ;

        
    }
};