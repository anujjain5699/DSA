#include<bits/stdc++.h>
using namespace std;
int minSteps(int n){
    if(n==1)return 0;
    int minus=INT_MAX,divide2=INT_MAX,divide3=INT_MAX;
    //minus by 1
    minus=minSteps(n-1);

    //divide2=0,divide3=0;
    //divide by 2
    if(n%2==0){
        divide2=minSteps(n/2);
    }
    //divide by 3
    if(n%3==0){
        divide3=minSteps(n/3);
    }
    return 1+min(minus,min(divide2,divide3));
}
int main(){
    int n;
    cin>>n;
    cout<<minSteps(n);
    return 0;
}