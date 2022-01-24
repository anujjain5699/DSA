/*
Trapped Water In Bars

Ninja was feeling bored today. He went for a walk and thought of a problem. You are given 'N' bars where each bar
has an integral length denoted by an array ARR[i]. It represents an elevation map wherein ARR[i] denotes the elevation
of the i-th bar. Your task is to write a function that returns the total amount of rainwater that can be trapped in these elevations.
Note :
The width of each bar is the same and is equal to 1.
Input format :
The first line contains an integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains an integer 'N' representing the size of the array/list.

The second line contains 'N' single space-separated integers representing the elevation of the bars.
Output Format :
For each test case, return the total water that can be trapped.

Output for every test case will be printed in a separate line.
Constraints :
1 <= T <= 10
0 <= N <= 10^4
0 <= ARR[i] <= 10^5

Time Limit: 1 sec
Sample Input 1 :
2
3
1 2 3
3
3 2 1
Sample Output 1 :
0
0
Sample Input 2 :
2
1
100
3
5 1 5
Sample Output 2 :
0
4
Sample Input 3 :
1
5
90 70 20 80 50
Sample Output 3 :
70
*/
#include<bits/stdc++.h>
using namespace std;

long getTrappedWater(long *arr, int n){
    long left[n];
    long right[n];
    long water = 0;
    left[0] = arr[0];
    for (long i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
    right[n - 1] = arr[n - 1];
    for (long i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
    for (long i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];
 
    return water;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        long *arr = new long[n];

        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        cout << getTrappedWater(arr, n) << "\n";

        delete[] arr;
    }
}