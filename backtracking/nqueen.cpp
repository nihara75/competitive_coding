/*
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10*/

//N-queens



#include <bits/stdc++.h>

int a[11][11];

bool isPossible(int n,int row,int column)
{
    int i,j;
    for(i=row-1;i>=0;i--)
    {
        if(a[i][column]==1)
            return false;
    }
    
    for(i=row-1,j=column-1;i>=0&& j>=0;i--,j--)
    {
        if(a[i][j]==1)
            return false;
    }
    
    for(i=row-1,j=column+1;i>=0&& j<n;i--,j++)
    {
        if(a[i][j]==1)
            return false;
    }
    return true;
}    

void Queens(int n,int row)
{
    if(row==n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cout<<a[i][j]<<" ";
        cout<<endl;
        return;
    }
    
    
        for(int j=0;j<n;j++)
        {
            if(isPossible(n,row,j))
            {
                a[row][j]=1;
                Queens(n,row+1);
                a[row][j]=0;
            }
        }
    return;
    
}    

void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */

memset(a,0,11*11*sizeof(int));
    
Queens(n,0);
    

}