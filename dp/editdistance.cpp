/*

Edit Distance - Problem
Send Feedback
You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note :
Strings don't contain spaces in between.
 Input format :
The first line of input contains the string S of length M.

The second line of the input contains the String T of length N.
Output format :
Print the minimum 'Edit Distance' between the strings.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec

*/

#include<string>
#include<algorithm>

int edit(string s1,string s2,int m,int n,int **dp)
{
   if(m==0)
       return n;
    if(n==0)
        return m;
    
    if(dp[m][n]>-1)
    {
        return dp[m][n];
    }
    int ans;
    
    if(s1[0]==s2[0])
       ans= edit(s1.substr(1),s2.substr(1),m-1,n-1,dp);
    else{
        ans=1+min(edit(s1.substr(1),s2,m-1,n,dp),min(edit(s1.substr(1),s2.substr(1),m-1,n-1,dp),
                  edit(s1,s2.substr(1),m,n-1,dp)));
    }
    dp[m][n]=ans;
    return ans;
}    

int editDistance(string s1, string s2)
{
	//Write your code here
    int m=s1.length();
    int n=s2.length();
    
    int **dp=new int *[m+1];
    for(int i=0;i<m+1;i++)
    {
        dp[i]=new int[n+1];
        for(int j=0;j<n+1;j++)
        {
            dp[i][j]=-1;
        }
        
    }
 return edit(s1,s2,m,n,dp);
}