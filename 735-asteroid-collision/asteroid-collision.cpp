class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0||st.empty()) 
            {   
                st.push(arr[i]);
            }
            else 
            {
                int flag=1;
                while(!st.empty()&&st.top()>0)
                {
                    if(st.top()>abs(arr[i])) 
                    {flag=0;
                    break;}
                    else if(st.top()==abs(arr[i]))
                    {
                         st.pop();
                         flag=0;
                         break;
                    }
                    else 
                    {
                        st.pop();
                    }
                }
                if(flag==1) st.push(arr[i]);
                
            }
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};