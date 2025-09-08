class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
       
        for(int i=1;i<n;i++)
        {
            int x=i;
            int y=n-i;
            int flag=1;
            while(x>0)
            {
                if(x%10==0)
                {
                    flag=0;
                }
                x/=10;
            }
            while(y>0)
            {
                if(y%10==0)
                {
                    flag=0;
                }
                y/=10;
            }
            if(flag==0) continue;
            return {i,n-i};
        }
        return {1,n-1};
        
    }
};