/*
N-Queen Problem

You are given N, and for a given N x N chessboard, find a way to place N queens such that no
queen can attack any other queen on the chess board. A queen can be killed when it lies in the
same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Note: Don't print anything if there isn't any valid configuration.
Input Format:
The first line of input contains an integer, that denotes the value of N.     
Output Format :
In the output, you have to print every board configuration in a new line. Every configuration
will have N*N board elements printed row wise and are separated by space. The cells where queens
are safe and placed, are denoted by value 1 and remaining all cells are denoted by value 0.
Please refer to sample test cases for more clarity.
Constraints :
1 <= N <= 10
Time Limit: 1 second
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
*/
#include<bits/stdc++.h>
using namespace std;

void print(int **board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
    }
    cout<<endl;
}

bool ispossible(int **board,int n,int i,int j){
    //check col
    for(int row=0;row<n;row++){
        if(board[row][j]==1)return false;
    }
    //check diagonal left top
    for(int row=i,col=j;row>=0 && col>=0;row--,col--){
        if(board[row][col]==1)return false;
    }
    //check diagonal right top
    for(int row=i,col=j;row>=0&&col<n;row--,col++ ){
         if(board[row][col]==1)return false;
    }
    return true;
}

void findAllPossible(int **board, int n,int i,int j){
    if(i==n){
        print(board,n);
    }
    for(int col=j;col<n;col++){
        if(ispossible(board,n,i,col)){
            board[i][col]=1;
            //check next row first column
            findAllPossible(board,n,i+1,0);
            board[i][col]=0;
        }
    }
}

void placeNQueens(int n){
    int **board=new int*[n];
    for(int i=0;i<n;i++){
        board[i]=new int[n];
    }
    for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
            board[i][j]=0;
         }
    }
    findAllPossible(board,n,0,0);
    for(int i=0;i<n;i++){
        delete board[i];
    }
    delete board;
}

int main(){    
    int n;
    cin>>n;
    placeNQueens(n);
    return 0;
}