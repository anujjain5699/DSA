/*
Buying And Selling Stock

You have been given the prices of 'N' stocks in an array where each array element represents the stock price for that day.
You need to find the maximum profit which you can make by buying and selling the stocks. You may make as many transactions
as you want but can not have more than one transaction at a time i.e, if you have the stock, you need to sell it first, and
then only you can buy it again.
Input format :
The first line contains an integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains an integer 'N' representing the total number of days for which you have stock prices.

The second line contains 'N' single space-separated integers representing the price of the stock on i-th day.
Output Format :
For each test case, print the maximum profit that you can earn.

Output for every test case will be printed in a separate line.
Note :
You are not required to print anything explicitly. Just implement the function.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1 :
1
7
1 2 3 4 5 6 7
Sample Output 1 :
6
Explanation :
We can make the maximum profit by buying the stock on the first day and selling it on the last day.
Sample Input 2 :
1
7
7 6 5 4 3 2 1
Sample Output 2 :
0
Explanation :
We can make the maximum profit by not buying the stock.
*/
#include<bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *values, int n)
{
    long max_profit=0;
    for(int i=1;i<n;i++){
        if(values[i]>values[i-1]){
            max_profit+=values[i]-values[i-1];
        }
    }
    return max_profit;
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

        cout << getMaximumProfit(arr, n) << "\n";

        delete[] arr;
    }
}