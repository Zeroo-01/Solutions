class Solution {
public:
    vector<int> sumZero(int n) {
       vector<int>arr;
       if(n%2!=0)
       {
        arr.push_back(0);
       }
       int i=1;
       while(n>1)
       {
            arr.push_back(i);
            arr.push_back(-i);
            i++;
            n-=2;
       }
       return arr;
    }
};