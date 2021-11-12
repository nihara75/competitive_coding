/*

iven two strings, 'S' and 'T' with lengths 'M' and 'N', find the length of the 'Longest Common Subsequence'.
For a string 'str'(per se) of length K, the subsequences are the strings containing characters in the same relative order as they are present in 'str,' but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K.
Example :
Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.
Input format :
The first line of input contains the string 'S' of length 'M'.

The second line of the input contains the string 'T' of length 'N'.
Output format :
Return the length of the Longest Common Subsequence.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

*/

#include<string>
#include<algorithm>
int lcsHelp(string s1,string s2,int m,int n, int **dp)
{
    if(m==0||n==0)
        return 0;
    if(dp[m][n]>-1)
        return dp[m][n];
    int ans;
    if(s1[0]==s2[0])
        ans=1+lcsHelp(s1.substr(1),s2.substr(1),m-1,n-1,dp);
    else 
    {
        int a=lcsHelp(s1.substr(1),s2,m-1,n,dp);
        int b=lcsHelp(s1,s2.substr(1),m,n-1,dp);
        ans=max(a,b);
    }
    dp[m][n]=ans;
    return ans;
}





int lcs(string s, string t)
{
	//Write your code here
    int m=s.length();
    int n=t.length();
    int **dp=new int*[m+1];
    for(int i=0;i<m+1;i++)
        dp[i]=new int[n+1];
    for(int i=0;i<m+1;i++)
        for(int j=0;j<n+1;j++)
            dp[i][j]=-1;
  return  lcsHelp(s,t,m,n,dp);
}