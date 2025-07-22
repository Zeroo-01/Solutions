class Solution {
public:
int div(int n,int x)
{
    return (x*((n/x)*((n/x)+1))/2);
}
    int sumOfMultiples(int n) {
        return div(n,3)+div(n,5)+div(n,7)-div(n,15)-div(n,21)-div(n,35)+div(n,105);
        
    }
};