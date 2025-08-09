class Solution {
public:
vector<int>fnse(vector<int>&arr)
    {
        int n=arr.size();
        vector<int>nse(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.empty()) nse[i]=n;
            else nse[i]=(st.top());
            st.push(i);
        }
        return nse;
    }
    vector<int>fpse(vector<int>&arr)
    {
        int n=arr.size();
        vector<int>pse(n,0);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.empty()) pse[i]=-1;
            else pse[i]=(st.top());
            st.push(i);
        }
        return pse;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>arr(m,0);int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1') arr[j]++;
                else arr[j]=0;
            }
            vector<int>nse=fnse(arr);
        vector<int>pse=fpse(arr);
        
        for(int i=0;i<m;i++)
        {
            
            int height=nse[i]-pse[i]-1;
            int area=arr[i]*height;
            ans=max(ans,area);
        }
        }
        
        return ans;


    }
};