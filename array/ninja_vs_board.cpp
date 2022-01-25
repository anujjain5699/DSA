
/*
Ninja vs Board

Ninja is feeling bored today. So he went for a walk and thought of a problem. Can you help him in solving it?
He has a 2D board ‘ARR’ with ‘N’ rows and ‘M’ columns. He wants is to find a rectangle having the maximum sum on the board.
Rectangle sum is the sum of values of integers present within its boundary.
For Example
Consider following matrix:

The rectangle (1,1) to (3,3) is the rectangle with the maximum sum, i.e. 29.

Input Format
The first line of input contains an integer ‘T’ denoting the number of test cases to run. Then the test cases follow.

The first line of each test case contains two space-separated integers ‘N’ and ‘M’ denoting the number of rows and
number of columns respectively.

The next ‘N’ lines contain ‘M’ space-separated integers denoting the elements of ARR.
Output Format
For each test case, print the value of the sum for the maximum sum rectangle.

Print the output of each test case in a separate line.
Note
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints
1 <= T <= 10
1 <= M, N <= 75
-10^5 <= ARR[i][j] <= 10^5

Time Limit: 1 sec
Sample Input 1
2
1 2
-1 1
2 2
-1 1
2 2
Sample Output 1
1
4

Sample Input 2
1
4 5
1 2 -1 -4 -20
-8 -3  4 2 1
3  8 10 1 3
-4 -1 1 7 -6
Sample Output 2
29

*/
#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(N * M * M)
    Space complexity: O(N)
    
    Where N denotes the number of rows of the matrix and M denotes the number of columns of the matrix.

*/

int kadaneAlgorithm(int arr[], int n)
{
	int sum = 0;
	
	int maxSum = INT_MIN;
    
    // Traverse the array.
	for(int currIndex = 0; currIndex < n; currIndex++)
	{
		sum += arr[currIndex];

		if(maxSum < sum)
		{
			maxSum = sum;
		}
		
		if(sum < 0)
		{
			sum = 0;
		}
	}

	return maxSum;
}

int maxSumRectangle(vector<vector<int>>& arr, int n, int m)
{
	int maxSum = INT_MIN;
	
    // Initialize a 1-D array.
	int temp[n];
    
    // check for all possible left and right boundaries.
	for(int left = 0; left < m; left++)
	{
		for(int i = 0; i < n; i++)
		{
			temp[i] = 0;
		}

		for(int right = left; right < m; right++)
		{
			for(int i = 0; i < n; i++)
			{
				temp[i] += arr[i][right];
			}
            
            // Function to find maximum sum of sub array of array 'temp'.
			int sum = kadaneAlgorithm(temp, n);
            
            // Update 'maxSum'.
			if(sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}

	return maxSum;
}

class Runner
{
    int t;
    vector<vector<vector<int>>> arr;

public:
    void takeInput()
    {
        cin >> t;
        for (int c = 0; c < t; c++)
        {
            int n, m;
            cin >> n >> m;
            vector<vector<int>> mat;
            for (int i = 0; i < n; i++)
            {
                vector<int> temp(m);
                for (int j = 0; j < m; j++)
                {

                    cin >> temp[j];
                }

                mat.push_back(temp);
            }

            arr.push_back(mat);
        }
    }

    void execute()
    {
        vector<vector<vector<int>>> arrCopy = arr;
        for (int i = 0; i < t; i++)
        {
            int n = arrCopy[i].size();
            int m = arrCopy[i][0].size();
            int ans = maxSumRectangle(arrCopy[i], n, m);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int n = arr[i].size();
            int m = arr[i][0].size();
            int ans = maxSumRectangle(arr[i], n, m);
            cout << ans << "\n";
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Runner runner;

    runner.takeInput();
    runner.executeAndPrintOutput(); 
 
    return 0;
}