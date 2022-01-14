#include<bits/stdc++.h>
using namespace std;

void kSortedArray(int input[],int n,int k){
    priority_queue<int>pq;
    for(int i=0;i<k;i++)pq.push(input[i]);

    int j=0;
    for(int i=k;i<n;i++){
        input[j]=pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }

    while(!pq.empty()){
        input[j]=pq.top();
        pq.pop();
        j++;
    }
}

int main(){
    int input[]={6,5,3,2,8,10,9};
    int size=sizeof(input)/sizeof(input[0]);
    int k=3;
    kSortedArray(input,size,k);
    for(int i=0;i<size;i++){
        cout<<input[i]<<" ";
    }
}