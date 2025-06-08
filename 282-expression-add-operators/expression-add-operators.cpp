class Solution {
public:
    void helper(string &num,int target,int pos,long eval,long last,string ds,vector<string>&ans)
    {
        if(pos==num.size())
        {
            if(eval==target)
            {
            ans.push_back(ds);
            }
            return;
        }
        for(int i=pos;i<num.size();i++)
        {
            if(i!=pos&&num[pos]=='0') break;
            
            string part=num.substr(pos,i-pos+1);
            long curr=stoll(part);
            if(pos==0)
            {
                helper(num,target,i+1,curr,curr,part,ans);
            }
            else
            {
                helper(num,target,i+1,eval+curr,curr,ds+"+"+part,ans);
                helper(num,target,i+1,eval-curr,-curr,ds+"-"+part,ans);
                helper(num,target,i+1,curr*last+eval-last,last*curr,ds+"*"+part,ans);
            }
        }

    }
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        if(num.empty()) return ans;
        string ds="";
        helper(num,target,0,0,0,ds,ans);
        return ans;
    }
};