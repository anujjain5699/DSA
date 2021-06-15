#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int x, long long int y)
{
    return y?gcd(y,x%y):x;
}
long long int lcm(long long int a, long long int b) {
 
    return (a*b) / gcd(a,b);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        cout<<gcd(x,y)<<" "<<lcm(x,y)<<endl;
    }
    return 0;
}