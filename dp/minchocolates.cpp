/*

Minimum Number of Chocolates
Send Feedback
Miss. Noor Rashid is a teacher. She wants to give some chocolates to the students in her class. All the students sit in a line, and each of them has a score according to performance. Noor wants to give at least one chocolate to each student. She distributes chocolates to them such that If two students sit next to each other, then the one with the higher score must get more chocolates. Miss. Noor wants to save money, so she wants to minimize the total number of chocolates.
Note :
When two students have an equal score, they are allowed to have a different number of chocolates. 
Input Format:
The first line of the input contains an integer value of N. It denotes the total number of students in Noor's class.

The second line of the input contains N integer values denoting the score of each of the students. A single space will separate them.
Output Format:
Print the minimum number of chocolates Noor must give.
Constraints
1 <= N <= 10^5
1 <= score <= 10^5

Time Limit: 1 sec

*/

int getMin(int *arr, int n)
{
	//Write your code here
    int *dp=new int[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
            dp[i]=dp[i-1]+1;
        if(arr[i]<=arr[i-1])
            dp[i]=1;
        
    }
    
    for(int i=n;i>0;i--)
    {
        if(arr[i]<arr[i-1]&& dp[i]>=dp[i-1])
            dp[i-1]=dp[i]+1;
        
    }
    for(int i=0;i<n;i++)
        sum+=dp[i];
    return sum;
        
}