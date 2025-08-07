class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(k==n) return "0";
        if(n==1) return num;
        stack<char>st;
        st.push(num[0]);

        for(int i=1;i<n;i++)
        {
        while(!st.empty() && k>0 && num[i]<st.top())
        {
            
                st.pop();
                k--;
        }
            st.push(num[i]);
   
        }
        
        while(k!=0&&!st.empty())
        {
            st.pop();
            k--;
        }
        
        string arr;
        while(!st.empty())
        {
            arr.push_back(st.top());
            st.pop();
        }
        reverse(arr.begin(), arr.end());
        int j=0;
        while(arr[j]=='0'&&j<arr.size())
        {
            j++;
        }
        arr=arr.substr(j);
        if(arr.empty()) return  "0";
        return arr;
    }
};