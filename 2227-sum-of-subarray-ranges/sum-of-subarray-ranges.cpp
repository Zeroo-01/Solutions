class Solution {
public:
    vector<int> fnse(vector<int>& arr)
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
            if(st.empty())
            {
                nse[i]=n;
            }
            else
            {
                nse[i]=st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> fnge(vector<int>& arr)
    {
        int n=arr.size();
        vector<int>nge(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&arr[st.top()]<arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                nge[i]=n;
            }
            else
            {
                nge[i]=st.top();
            }
            st.push(i);
        }
        return nge;
    }
    vector<int> fpse(vector<int>& arr)
    {
        int n=arr.size();
        vector<int>pse(n,0);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&arr[st.top()]>arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                pse[i]=-1;
            }
            else
            {
                pse[i]=st.top();
            }
            st.push(i);
        }
        return pse;
    }
    vector<int> fpge(vector<int>& arr)
    {
        int n=arr.size();
        vector<int>pge(n,0);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&arr[st.top()]<=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                pge[i]=-1;
            }
            else
            {
                pge[i]=st.top();
            }
            st.push(i);
        }
        return pge;
    }

    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse= fnse(arr);
        vector<int>pse= fpse(arr);
        vector<int>nge= fnge(arr);
        vector<int>pge= fpge(arr);
        long long mini=0;
        long long maxi=0;
        for(int i=0;i<n;i++)
        {
            int leftm=i-pse[i];
            int rightm=nse[i]-i;
            int left=i-pge[i];
            int right=nge[i]-i;

            mini=mini+(1LL*leftm*rightm*arr[i]);
            maxi=maxi+(1LL*left*right*arr[i]);

        }
        return maxi-mini;


    }
};