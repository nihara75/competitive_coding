/*
Largest Bitonic Subarray
Send Feedback
You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic subsequence
Input Constraints:
1<= N <= 10000
*/


 	
	int longestBitonicSubarray(int *input, int n) {
		
	/* Don't write main().
     	* the input is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	*/
     	
     	
        
        int *inc=new int[n];
        int *dec=new int[n];
        int *total=new int[n];
        
        inc[0]=1;
        dec[n]=1;
        
        for(int i=1;i<n;i++)
        {
            inc[i]=1;
            for(int j=i-1;j>=0;j--)
            {
                if(input[i]<=input[j])
                {
                    continue;
                }
                int ans=inc[j]+1;
                if(ans>inc[i])
                    inc[i]=ans;
            }
        }
        
        for(int k=n-1;k>=0;k--)
        {
            dec[k]=1;
            for(int j=k+1;j<n;j++)
            {
                
                if(input[k]<=input[j])
                {
                    continue;
                }
                int ans=dec[j]+1;
                if(ans>dec[k])
                    dec[k]=ans;
            }
        }
        
        int best=0;
        
        for(int i=0;i<n;i++)
        {
            total[i]=inc[i]+dec[i]-1;
            if(total[i]>best)
                best=total[i];
        }
        
        return best;
        
        
        
        
        
        
        
     	
 	}