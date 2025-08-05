class Solution {
public:
    int numOfUnplacedFruits(vector<int>& arr, vector<int>& nums) {

        int n=nums.size();
        vector<int>flag(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {

            for(int j=0;j<n;j++)
            {
                if(flag[j]==0&&arr[i]<=nums[j])
                {
                   flag[j]=1;
                   count++;
                   break;
                }
            }
           
        }
        return n-count;
    }
};