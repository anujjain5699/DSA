/*
Ceiling Of Array

It is the test day at the DOJO, and the Ultimate Ninja Ankush has given you an array and asked to find the ceiling ‘X’,
to prove to the ultimate ninja Ankush that you are worthy, and to find the ceiling of the array.
More Formally, you are given a sorted array A of integers having size N and a number X. Your task is to return the ceiling of 'X'.
for the given list. Return -1 if the ceiling does not exist.
Ceiling of X is the smallest element in the array greater than or equal to X.
Note: you are not allowed to use inbuilt functions like lower_bound() etc.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases to run. Then the test cases follow.

The first line of each test case contains two integers ‘N’ and 'X', where N represents the size of the array.

The next line contains N integers, denoting the elements of the given array.
Output Format :
For each test case print a single integer denoting the ceiling of X.

Output for each test case will be printed in a separate line,
Note :
You are not required to print anything, it has already been taken care of. Just implement the function.
Constraints :
1 <= ‘T’ <= 10      
1 <= ‘N’ <= 2 * 10^5      
1 <= ‘A[i]’ <= 10^9
Time limit: 1 sec
Sample Input 1 :
2
6 5
1 2 3 4 5 6
6 3
4 5 6 7 8 9
Sample Output 1 :
5
4
Explanation of sample input 1 :
For test case 1:
5 is the element in the array greater than equal to X=5.

For test case 2:
4 is the element in the array greater than equal to X=3.
Sample Input 2 :
2
3 7
1 2 9
6 2
1 1 1 1 1 1
Sample Output 2 :
9
-1
*/
#include<bits/stdc++.h>
using namespace std;

int ceilingInSortedArray(int n, int x, vector<int> &arr) {
    int diff=INT_MAX;
    int ans=0;
    for(int i=0;i<n;i++){
        if(arr[i]>=x&&(arr[i]-x)<diff){
            diff=arr[i]-x;
            ans=arr[i];
        }
    }
    return ans!=0?ans:-1;
}

class Runner{
    int t;
    vector<int> N,X;
    vector<vector<int>> arr;

public:
    void takeInput(){
        cin >> t;
        N.resize(t);
        X.resize(t);
        arr.resize(t);
        for (int i = 0; i < t; i++){
            cin >> N[i] >> X[i];
            arr[i].resize(N[i]);
            for (int j = 0; j < N[i]; j++){
                cin >> arr[i][j];
            }
        }
    }

    void execute(){
        vector<vector<int>> cpy = arr;
        for (int i = 0; i < t; i++){
            int ans = ceilingInSortedArray(N[i], X[i], cpy[i]);
        }
        vector<vector<int>>().swap(cpy);
    }

    void executeAndPrintOutput(){
        for (int i = 0; i < t; i++){
            int ans = ceilingInSortedArray(N[i], X[i], arr[i]);
            cout << ans << "\n";
        }
    }
};

int main()
{

#ifndef ONLINE_JUDGE
   // freopen("testcases/Large/in/input11.txt", "r", stdin);
   // freopen("testcases/Large/out/output11.txt", "w", stdout);
#endif
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}