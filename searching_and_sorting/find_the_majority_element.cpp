/*
Find The Majority Element

Given an array ‘ARR’ of N integers and an integer ‘K’. Find all elements of ‘ARR’ which occur more than or 
equals to ‘N / K’ times in ‘ARR’.
For example:
Given array ‘ARR = { 2, 3, 3, 3, 3, 2, 2, 2 }’ and ‘K = 2’
Here the answer is {2, 3} because ‘2’ occurs ‘4’ times and ‘3’ occurs ‘4’ times which is more than or equals to ‘8/ 2 = 4’.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases.
The next ‘T’ lines represent the ‘T’ test cases.

The first line of input contains two space-separated integers ‘N’ and ‘K’. Where ‘N’ denotes the number of elements 
in the array ‘ARR’ and ‘K’ is given integer number.

The second line of input contains the ‘N’ space-separated integer which denotes the element of array ‘ARR’ and ‘K’ is 
given a second integer number.
Output Format:
For every test case, print all elements of ‘ARR’ which occur more than or equals to ‘N/K’ times in ‘ARR’.

Output for each test case will be printed in a separate line.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraint :
1 <= T <= 10^2
1 <= K <= N <= 5*10^3 ( N is multiple of K)
-10^9 <= ARR[i] <= 10^9

Time Limit: 1 sec
Sample Input 1:
2
2 2
1 1
8 8
1 2 1 3 1 4 1 5
Sample Output 1:
1
1 2 3 4 5
Explanation For Sample Input 1:
Test Case 1:
Given array ‘ARR = { 1, 1 }’ and ‘K = 2’.

The only element 1 has frequency more than or equal to ‘N / K' = 2 / 2 = 1.

Test Case 2:
Given array ‘ARR = { 1, 2, 1, 3, 1, 4, 1, 50 }’ and ‘K = 8’.
‘N / K = 8 / 8 = 1’ so all the elements 1, 2, 3, 4, 5 have frequency more than ‘1’.
Sample Input 2:
2
10 2
2 2 3 3 4 4 5 2 2 2
4 1
1 1 1 1
Sample Output 2:
2
1
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> countTheNumber(vector<int> &arr, int n, int k) 
{
    vector<int>v;
	unordered_map<int,int>mp;
    for(int i=0;i<n;i++)mp[arr[i]]++;
    for(unordered_map<int, int>::iterator itr=mp.begin();itr!=mp.end();itr++){
        if(itr->second>=n/k)v.push_back(itr->first);
    }
    return v;
}

class Runner {
    int t;

    vector<vector<int>> arr;
    vector<int> k;

public:

    void takeInput() {

        cin >> t;

        arr.resize(t);

        for(int c = 0; c < t; c++) {
            int n,k1;
            cin>>n>>k1;
            k.push_back(k1);

            vector<int> temp(n);

            for(int i=0;i<n;i++){
                cin >> temp[i];
            }

            arr[c] = temp;
        }
        
    }

    void execute() {

        for (int i = 0; i < t; i++){
            vector<int> copy = arr[i];
            vector<int> ans=countTheNumber(copy,copy.size(),k[i]);
        }
    }

    void executeAndPrintOutput(){

        for (int i = 0; i < t; i++) {

            vector<int> ans = countTheNumber(arr[i],arr[i].size(),k[i]);
            sort(ans.begin(), ans.end());
            for(int i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";
            cout<<"\n";
        }
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Runner runner;

    runner.takeInput();
    runner.executeAndPrintOutput(); 
 
    return 0;
}