/*
Rearrange In ZigZag Order

You are given an array/list 'ARR' of 'N' distinct elements. Rearrange 'ARR' elements in a zig-zag fashion
such that for every odd position ‘i’ in the array 'ARR', 'ARR'[i] should be greater than 'ARR'[i-1] and 'ARR'[i] should
be greater than 'ARR'[i+1].

For example:
Given ‘N’ = 4, and 'ARR' = { 4, 3, 2, 1} 
Then a possible zig zag rearrangement is 3, 4, 1, 2.
Note:
You are supposed to return the modified array. If there are multiple answers for a particular array, any of the possible solutions are accepted. It is given that a zig-zag array is always possible for a given array.
Input format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

The first line of each test case contains a single integer, ‘N,’ where ‘N’ is the number of elements of the array.

The second line of each test case contains ‘N’ space-separated integers, denoting 'ARR' elements.
Output Format :
For each test case, print the elements of the given 'ARR' arranged in a zig-zag manner. 

The runner function will print a single line containing a single integer which denotes whether the returned array is in zig-zag fashion or not.
Note:
You are not required to print the expected output; it has already been taken care of. Just implement the function.
Constraints:
1 <= ‘T’ <= 10
1 <= ‘N’ <= 5*10^3
0 <= 'ARR'[i] <= 10 ^ 6

Time Limit: 1sec.
Sample Input 1 :
2
4
4 3 2 1
5
2 4 6 8 10
Sample Output 1 :
1
1   
Explanation of the Sample Input 1:
For the first test case :  
One possible configuration can be 3 4 1 2. Therefore, the array can be converted into a zig-zag fashion.

For the second test case:
One possible configuration can be 2, 8, 6, 10, 4. Therefore the given array can be converted.
Sample Input 2 :
2
4
3 2 4 5
5
6 1 3 2 5
Sample Output 2 :
1
1
*/

#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr,int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
    return;
}
vector<int> zigZag(vector<int> &arr, int n)
{
    int flag=0;
    for(int i=1;i<n;i++){
        if(flag==0 && arr[i-1]>arr[i]){
            swap(arr,i-1,i);
        }
        else if(flag==1 && arr[i-1] < arr[i])swap(arr,i-1,i);
            flag=!flag;
    }
    return arr;
}
class Runner
{
	int t;
	vector<vector<int> > arr;

public:
	void takeInput()
	{
		cin >> t;
		for (int d = 0; d < t; d++)
		{
			vector<int> temp;
			int n ;
			cin >> n ;

			for (int i = 0 ; i < n ; i++) {
				int x ;
				cin >> x ;
				temp.push_back(x) ;
			}

			arr.push_back(temp) ;
		}
	}

	void execute()
	{
		vector<vector<int> > newArr = arr ;
		for (int i = 0; i < t; i++)
		{
			vector<int> res = zigZag(newArr[i], newArr[i].size()) ;
		}
		newArr.clear() ;

	}
	bool check(vector<int> &arr, int n) {

		for (int i = 1 ; i < n ; i += 2) {
			if (i + 1 < n) {
				if (arr[i] < arr[i + 1]) {
					return false;
				}
			}

			if (arr[i] < arr[i - 1]) {
				return false;
			}
		}
		return true;
	}
	void executeAndPrintOutput()
	{
		for (int i = 0; i < t; i++)
		{
			vector<int> res = zigZag(arr[i], arr[i].size()) ;
			/*for (int i : res) {
				cout << i << " " ;
			} cout << endl ;*/
			cout << check(res, res.size()) << endl;
		}

	}
};
int main()
{
	Runner runner;
	runner.takeInput();
	runner.executeAndPrintOutput();
	return 0;
}