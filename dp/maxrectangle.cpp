/*
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100



*/

#include <bits/stdc++.h>
using namespace std;
int kadane(int a[],int n)
{
    int curr=0;
    int best=INT_MIN;
    for(int i=0;i<n;i++)
    {
        curr+=a[i];
        
        
        if(curr>best)
                best=curr;
        
        if(curr<0)
        {
            curr=0;
        }   
    }
    
    return best;
}   

int sumRec(int a[100][100],int n,int m)
{
    int ma=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int *temp=new int[m];
        for(int j=i;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                temp[k]+=a[j][k];
            }
            ma=max(ma,kadane(temp,m));
        }
    }
    
    return ma;
}



int main()
{
    
    int n,m;
    cin>>n>>m;
    int a[100][100];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    cout<<sumRec(a,n,m)<<endl;
    return 0;
}