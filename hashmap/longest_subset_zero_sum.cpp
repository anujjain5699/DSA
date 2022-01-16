/*
Longest subset zero sum

Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format
The first and only line of output contains length of the longest subarray whose sum is zero.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1:
10 
95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output 1:
5
Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 

Sample input2: 
6
1 2 3 4 -10 10
Sample output2:
5
*/
#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    if(n==0)return 0;
    unordered_map<int,int>mp;
    int max_length=0,sum=0;
    for(int i=0;i<n;i++){
        // Add current element to sum
        sum+=arr[i];
        if(arr[i]==0 && max_length==0)
            max_length=1;
        if(sum==0)
            max_length=i+1;
        // Look for this sum in Hash table
        if(mp.count(sum)>0){
            // If this sum is seen before, then update max_len
            max_length=max(max_length,i-mp[sum]);
        }else{
            // Else insert this sum with index in hash table
            mp[sum]=i;
        }
    }
    return max_length;
}

int main() {
    int size;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << lengthOfLongestSubsetWithZeroSum(arr, size);
    delete[] arr;
}