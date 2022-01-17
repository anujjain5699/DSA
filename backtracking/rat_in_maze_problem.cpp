/*
Rat In A Maze Problem
Send Feedback
You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat
starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all
the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move
from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell
of the given binary matrix.
Input Format
The first line of input contains an integer, that denotes the value of N.
Each of the following N lines denote rows of the binary matrix and contains either 0 or 1.
Each row of the binary matrix contains N elements. 
Output Format :
Every possible solution has to be printed on a separate line. Each of the possible solution will have N*N elements,
printed row wise and separated by space. The cells that are part of the path should be 1 and remaining all cells should be 0.
Please refer to sample test cases for more clarity.   
Constraints
1 <= N <= 18
0 <= Number of cells with value 1 <= 15
Time Limit: 1 second

Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 

Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 

*/
#include<iostream>
#include<cstring>
using namespace std;

bool checkMovable(int **maze,int n,int row,int col){
    if(row>=n || row<0 || col>=n || col<0 || maze[row][col]!=1)return false;
    return true;
}
        

void ratHelper(int **maze,int n, int **path, int row, int col){
    if(row==n-1 && col==n-1){
        path[row][col]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<path[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }

    if(checkMovable(maze,n,row,col) && path[row][col]!=1){
        path[row][col] = 1;
        ratHelper(maze,n,path,row-1,col);
        ratHelper(maze,n,path,row,col+1);
        ratHelper(maze,n,path,row+1,col);
        ratHelper(maze,n,path,row,col-1);
        path[row][col] = 0;
    }
}

void ratInAMaze(int n){

    int **maze=new int*[n];

    for(int i=0;i<n;i++){
        maze[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    int **path=new int*[n];

    for(int i=0;i<n;i++){
        path[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            path[i][j]=0;
        }
    }
    ratHelper(maze,n,path,0,0);
    for(int i=0;i<n;i++){
        delete maze[i];
        delete path[i];
    }
    delete maze;
    delete path;
}

int main()
{
    int n;
    cin>>n;
    ratInAMaze(n);
}