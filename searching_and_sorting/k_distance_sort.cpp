/*
K Distance Sort

Given an array 'ARR' of N elements, where each element is at most K distance away from its target position in the sorted array.
The task is to sort the original array.
Follow up
 Can you solve this problem in O(N log K) time?
For example:
Let us consider 'K' is 3, an element at index 4 in the sorted array, can be at indexes 1, 2, 3, 4, 5, 6, 7 in the given array
because the absolute difference of all these indices with 4 is at most 3.
Input Format:
The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains two space-separated integers N and K, the number of elements in the array and K as
specified in the problem statement.

The second line of each test contains N space-separated integers.
Output Format:
The only line of output of each test case should contain N space-separated integers denoting the sorted array.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function. 
Constraints:
1 <= T <= 100
1 <= K < N <= 5000
1 <= ARR[i] <= 10^9 

Time Limit: 1 sec
Sample Input 1:
1
7 3 
7 5 2 1 8 10 9
Sample Output 1:
1 2 5 7 8 9 10
Explanation For Sample Input 1:
We could move 7 from position 1 to as far as position 4 (as K=4) and we moved it to position 4 and it can be seen that after
that all elements to the left(i.e position 1 to 3) are less than 7, hence 10 is at its best position now. Similarly, we do this
for all the elements, to reach our answer. 
Sample Input 2:
1
8 4
10 9 8 7 4 70 60 50
Sample Output 2:
4 7 8 9 10 50 60 70
Explanation For Sample Input 2:
We could move 10 from position 1 to as far as position 5(as K=4) and we moved it to position 5 and it can be seen that after
that all elements to the left(i.e position 1 to 4) are less than 10, hence 10 is at its best position now.
Similarly we do this for all the elements, to reach our answer. 
*/
using namespace std;
#include<bits/stdc++.h>

vector < int > nearlySorted(vector < int > arr, int n, int k) {
	priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>v;
    for(int i=0;i<=k;i++)pq.push(arr[i]);
    for(int i=k+1;i<n;i++){
        v.push_back(pq.top());
        pq.pop();
        pq.push(arr[i]);
    }
    while(!pq.empty()){
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> array(n);
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }

        array = nearlySorted(array, n, k);
        for (int i = 0; i < n; i++)
        {
            cout << array[i] << " ";
        }

        cout << endl;
    }
}