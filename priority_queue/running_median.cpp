/*
Running Median

You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.
Input Format :
The first line of input contains an integer 'N', denoting the number of integers in the stream.

The second line of input contains 'N' integers separated by a single space.
Output Format :
Print the running median for every integer added to the running list in one line (space-separated).
Input Constraints
0 <= N <= 10 ^ 5
1 <= ARR[i] <= 10 ^ 5

Time Limit: 1 sec
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4

Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5 4 4 3 3
*/

/*

best approach : -
arr[] = 7 2 8 3 1 5
think about the result 1 2 3 | 5 7 8
to find median we need max from left half and min from right half simply{ top from max heap and top from min heap}
*/

#include<bits/stdc++.h>
using namespace std;

void findMedian(int *arr, int n)
{
    if(n==0)return;
    priority_queue <int, vector<int>, greater<int> >minheap;
    priority_queue<int> maxheap;

    //first element can be added in either heaps ,I am taking in max-heap
    maxheap.push(arr[0]);
    cout<<arr[0]<<" ";

    for(int i=1;i<n;i++){
        //if array element is smaller than top of max-heap then add it in max-heap otherwise min-heap
        if(maxheap.top()>arr[i]){
            maxheap.push(arr[i]);
        }else{
            minheap.push(arr[i]);
        }

        //check for size , size difference can't be greater than 1
        int minheapsize=minheap.size();
        int maxheapsize=maxheap.size();
        if(maxheapsize>minheapsize+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(maxheapsize+1<minheapsize){
            maxheap.push(minheap.top());
            minheap.pop();
        }

        //if total number of elements in both heaps is even then take top from both
        //otherwise take from heap which has greater size
        minheapsize=minheap.size();
        maxheapsize=maxheap.size();
        if((minheapsize+maxheapsize)%2==0){
            cout<<(minheap.top()+maxheap.top())/2<<" ";
        }
        else{
            if(minheapsize>maxheapsize)cout<<minheap.top()<<" ";
            else cout<<maxheap.top()<<" ";
        }
    }
}
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    findMedian(arr,n);
    delete[] arr;
}
