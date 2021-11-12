/*

You are given a magic grid A with R rows and C columns. In the cells of the grid, you will either get magic juice, which increases your strength by |A[i][j]| points, or poison, which takes away |A[i][j]| strength points. If at any point of the journey, the strength points become less than or equal to zero, then you will die.
You have to start from the top-left corner cell (1,1) and reach at the bottom-right corner cell (R,C). From a cell (i,j), you can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and you can not move outside the magic grid. You have to find the minimum number of strength points with which you will be able to reach the destination cell.
Input format:
The first line contains the number of test cases T. T cases follow. Each test case consists of R C in the first line followed by the description of the grid in R lines, each containing C integers. Rows are numbered 1 to R from top to bottom and columns are numbered 1 to C from left to right. Cells with A[i][j] < 0 contain poison, others contain magic juice.
Output format:
Output T lines, one for each case containing the minimum strength you should start with from the cell (1,1) to have a positive strength through out his journey to the cell (R,C).
*/
#include<limits.h>
#include<stdio.h>
int getMinimumStrength(int** grid, int n, int m) {
	// Write your code here
    int **temp=new int*[n];
    for(int i=0;i<n;i++)
        temp[i]=new int[m];
    temp[n-1][m-1]=1;
    temp[n-1][m-2]=1;
    temp[n-2][m-1]=1;
    
    for(int i=n-3;i>=0;i--)
    {
        if(grid[i+1][m-1]<0)
            temp[i][m-1]=temp[i+1][m-1]-grid[i+1][m-1];
        else
        {
            temp[i][m-1]=max(1,temp[i+1][m-1]-grid[i+1][m-1]);
        }
    }
    
    for(int i=m-3;i>=0;i--)
    {
        if(grid[n-1][i+1]<0)
            temp[n-1][i]=temp[n-1][i+1]-grid[n-1][i+1];
        else
        {
            temp[n-1][i]=max(1,temp[n-1][i+1]-grid[n-1][i+1]);
        }
    }
    
    for(int i=n-2;i>=0;i--)
        for(int j=m-2;j>=0;j--)
        {
            int down,right;
            if(grid[i][j+1]<0)
                right=temp[i][j+1]-grid[i][j+1];
            else{
                right=max(1,temp[i][j+1]-grid[i][j+1]);
            }
            
            if(grid[i+1][j]<0)
                down=temp[i+1][j]-grid[i+1][j];
            else{
                down=max(1,temp[i+1][j]-grid[i+1][j]);
            }
            
            temp[i][j]=min(right,down);
        }
   
    
    return temp[0][0];
}