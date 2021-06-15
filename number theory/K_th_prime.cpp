#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
bool ar[90000001];
void sieve()
{
    int maxN=90000000;
    ar[0]=ar[1]=true;
    for(int i=2;i*i<=maxN;i++)
    {
        if(!ar[i])
        {
            for(int j=i*i;j<=maxN;j+=i)
            {
                ar[j]=true;
            }
        }
    }
    for(int i=2;i<=maxN;i++)
    {
        if(!ar[i])
        primes.push_back(i);
    }
}
int main()
{
    int t;
    cin>>t;
    sieve();
    while(t--)
    {
        int  n;
        cin>>n;
        cout<<"-->"<<primes[n-1]<<endl;
    }
    return 0;
}