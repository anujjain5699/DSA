/*
Subarray Sum Of Infinite Array

Ninja was feeling bored today. So he went for a walk and thought of a problem. You are given an array, “A” of N integers.
A new array “B” is defined as a concatenation of array “A” for an infinite number of times.
For example, if the given array “A” is [1,2,3] then, infinite array “B” is [1,2,3,1,2,3,1,2,3,.......].
You are given Q queries, where each query consists of two integers “L“ and “R”. Your task is to find the sum of 
the subarray from index “L” to “R” (both inclusive) in the infinite array “B” for each query.

Note :
The value of the sum can be very large, return the answer as modulus 10^9+7.
Input format :
The first line of input contains a single integer T, representing the number of test cases or queries to be run.

Then the T test cases follow. 

The first line of each test case contains a single integer N, denoting the size of the array “A”.

The second line of each test case contains N single space-separated integers, elements of the array “A”.

The third line of each test case contains a single integer Q, denoting the number of queries.

Then each of the Q lines of each test case contains two single space-separated integers L, and R denoting the left and the
right index of the infinite array “B” whose sum is to be returned. 

Output format :
For each test case, print Q space-separated integers that denote the answers of the given Q queries. Print the answer to each
test case in a separate line.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 100
1 <= N <= 10^4   
1 <= A[i] <= 10^9
1 <= Q <= 10^4
1 <= L <= R <= 10^18

Time Limit: 1 sec
Sample Input 1 :
1
3
1 2 3
2
1 3
1 5
Sample Output 1 :
6 9
Explanation to Sample Input 1 :
For the first test case, the given array A is [1,2,3] therefore the infinite array “B” will be [1,2,3,1,2,3,1,2,3,.......]. So the answer for the given first query is 6 because the sum of the subarray from index 1 to 3 of infinite array “B” i.e. (B[1]+B[2]+B[3]) is 6.

For the given second query is 9 because the sum of the subarray from index 1 to 5 of array “B” .ie (B[1]+B[2]+B[3]+B[4]+B[5]) is 9.
Sample Input 2 :
1
4
5 2 6 9
3
1 5
10 13
7 11
Sample Output 2 :
27 22 28
*/
#include <iostream>
#include <vector>
using namespace std;

/*
    Time Complexity:O(Q+N).
    Space Complexity:O(N).

    Where N is the size of the given array, and Q is the number of queries given.
*/

int mod = 1000000007;

// Function to calculate prefix sum upto index x of the infite array.
long long func(vector<long long> &sumArray, long long x, long long n) {

    // Number of times the given array comes completely upto index x.
    long long count = (x / n) % mod;

    long long res = (count * sumArray[(int) n]) % mod;

    // Adding the remaining elements sum.
    res = (res + sumArray[(int) (x % n)]) % mod;

    return res;
}

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {

    // It stores answer for each query.
    vector<int> ans;

    // It store cumulative sum where sumArray[i] = sum(A[0]+..A[i]).
    vector<long long> sumArray(n + 1);

    for (int i = 1; i <= n; i++) {
        sumArray[i] = (sumArray[i - 1] + arr[i - 1]) % mod;
    }

    // Traversing the given queries.
    for (int i = 0; i < queries.size(); i++) {
        vector<long long> range = queries[i];
        long long l = range[0];
        long long r = range[1];

        // It stores the prefix sum from index 0 to index r in an infinite array.
        long long rsum = func(sumArray, r, n);

        // It stores the prefix sum from index 0 to index l-1 in an infinite array.
        long long lsum = func(sumArray, l - 1, n);

        // Add answer for each query.
        ans.push_back((int) ((rsum - lsum + mod) % mod));

    }

    return ans;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cin >> q;
        vector<vector<long long>> queries;
        for(int i = 0; i < q; i++) {
            long long l, r;
            cin >> l >> r;
            queries.push_back({l, r});
        }

        vector<int> ans = sumInRanges(arr, n, queries, q);
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}