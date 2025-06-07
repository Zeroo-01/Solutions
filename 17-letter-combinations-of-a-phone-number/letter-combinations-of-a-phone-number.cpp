class Solution {
public:
void helper(string digits,int index,string &ds, vector<string>&ans, unordered_map<char,string>&mpp)
{
    if(index==digits.size())
    {
        ans.push_back(ds);
        return;
    }
    char curr=digits[index];
    string letters=mpp[curr];
    for(auto ch:letters)
    {
        ds.push_back(ch);
        helper(digits,index+1,ds,ans,mpp);
        ds.pop_back();
    }

}
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char,string>mpp={
            {'2',"abc"},{'3',"def"},
            {'4',"ghi"},{'5',"jkl"},
            {'6',"mno"},{'7',"pqrs"},
            {'8',"tuv"},{'9',"wxyz"}
        };
        vector<string>ans;
        string ds="";
        helper(digits,0,ds,ans,mpp);
        return ans;

    }
};