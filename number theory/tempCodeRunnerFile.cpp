#include<bits/stdc++.h>
using namespace std;
#define n 1000001
int a[n];
int p[n];
void sieve()
{
    a[0]=a[1]=0;
    for(int i=2;i<n;i++)a[i]=1;
    for(int i=2;i*i<n;i++)
    {
        if(a[i]==1){
            for(int j=i*i;j<n;j+=i)a[j]=0;
        }
    }
    int count=0;
    for(int i=1;i<n;i++)
    {
        if(a[i])count++;
        if(a[count])p[i]=1;
        else p[i]=0;
    }
    for(int i=1;i<n;i++)
    p[i]+=p[i-1];
}
int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        int l,r,count=0;
        cin>>l>>r;
        // for(int i=l;i<=r;i++)
        // {
        //     if(!a[i])count++;
        // }
        cout<<p[r]-p[l-1]<<endl;
    }
    return 0;
}