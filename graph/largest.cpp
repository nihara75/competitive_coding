/*

Largest Piece

It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.
Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.
Constraints :
1 <= N <= 1000
Time Limit: 1 sec
Sample Input 1:
2
1 1
0 1
Sample Output 1:
3

*/

#include<limits.h>

int check(vector<vector<int>> &cake,int n,int i,int j,bool **vis)
{
    if(i<0||j<0||i>n-1||j>n-1)
        return 0;
    if(cake[i][j]!=1 || vis[i][j])
        return 0;
    
    vis[i][j]=true;
    
    
    int count=0;
    count+=check(cake,n,i-1,j,vis);
    count+=check(cake,n,i,j+1,vis);
    count+=check(cake,n,i+1,j,vis);
    count+=check(cake,n,i,j-1,vis);
    
    
    
    
    
    
    
    
    
    return count+1;
}





int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    
    bool **vis=new bool*[n];
    for(int i=0;i<n;i++)
    {
        vis[i]=new bool[n];
        for(int j=0;j<n;j++)
            vis[i][j]=false;
    }
    int ans=INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<n;j++)
        {
            if(cake[i][j]==1 && !vis[i][j])
            {
                //vis[i][j]=true;
                ans=max(check(cake,n,i,j,vis),ans);
            }
        }
    }
    
    return ans;
}
