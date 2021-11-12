/*

Maximum Square Matrix With All Zeros
Send Feedback
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.
Input format :
The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.

Second-line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).
Output Format:
Print the size of maximum square sub-matrix.
 Constraints :
0 <= N <= 10^4
0 <= M <= 10^4

Time Limit: 1 sec

*/


int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
    if(n==0&&m==0)
        return 0;
    int maxc=0;
    int **temp=new int*[n];
    for(int i=0;i<n;i++)
    {
        temp[i]=new int[m];
        
    }
    
    if(arr[n-1][m-1]==0)
    {
        temp[n-1][m-1]=1;
        maxc=1;
    }
  
    else{
        temp[n-1][m-1]=0;
        
    }
    
    
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i][m-1]==0)
        {
            temp[i][m-1]=1;
        }else{
            temp[i][m-1]=0;
        }
        maxc=max(maxc,temp[i][m-1]);
    }
    
    
    
    for(int i=m-2;i>=0;i--)
    {
        if(arr[n-1][i]==0)
        {
            temp[n-1][i]=1;
        }else{
            temp[n-1][i]=0;
        }
        maxc=max(maxc,temp[n-1][i]);
    }
    
    
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            if(arr[i][j]==0)
            {
                if(temp[i+1][j]>=1 && temp[i][j+1]>=1 && temp[i+1][j+1]>=1)
				{
					temp[i][j]=1+min(temp[i+1][j+1], min(temp[i+1][j], temp[i][j+1]));
				}
				else
				{
					temp[i][j]=1;
				}
            }else{
                temp[i][j]=0;
            }
            maxc=max(maxc,temp[i][j]);
        }
    }
    
    
    return maxc;
}