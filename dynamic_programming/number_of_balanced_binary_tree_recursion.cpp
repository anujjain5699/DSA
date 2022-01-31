/*
Code : No. of balanced BTs using DP

Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible
binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 10^6
Time Limit: 1 sec

Sample Input 1:
3
Sample Output 1:
15

Sample Input 2:
4
Sample Output 2:
315

*/
#include <iostream>
using namespace std;

int balancedBTs(int n) {
 if(n<=1)return 1;
    int x=balancedBTs(n-1);
    int y=balancedBTs(n-2);
    int temp1=(int)(((long)(x)*x)%1000000007);
    int temp2=(int)((2*(long)(x)*y)%1000000007);
        int ans=(temp1+temp2)%1000000007;
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}