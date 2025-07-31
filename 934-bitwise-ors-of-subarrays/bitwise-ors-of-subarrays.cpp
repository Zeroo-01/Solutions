class Solution {
public:
    
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int>prev;
        unordered_set<int>ans;
        for(int i=0;i<n;i++)
        {
            unordered_set<int>curr;
            curr.insert(arr[i]);
           
            for(int j:prev)
            {
                curr.insert(j|arr[i]);
            }
            prev=curr;
            ans.insert(prev.begin(),prev.end());
        }
        return ans.size();
    }
};