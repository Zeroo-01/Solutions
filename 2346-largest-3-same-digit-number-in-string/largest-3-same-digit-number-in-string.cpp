class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        int i=0;
        int maxi=-1;
        
        while(i<n-2)
        {
            if(num[i]==num[i+2])
            {
                if(num[i]==num[i+1])
                {
                    string s=num.substr(i,3);
                    int x=stoi(s);
                    maxi=max(x,maxi);
                }
                
            }
            i++;
        }
        if(maxi==0) return "000";
        if(maxi!=-1) return  to_string(maxi);
        return "";
    }
};