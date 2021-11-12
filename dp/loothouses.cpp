/*

Loot Houses
Send Feedback
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
Output format :
Print the the maximum money that can be looted.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

*/

int getMax(int *arr,int n,int i,int *temp)
{
    if(i>=n)
        return 0;
    if(temp[i]>0)
        return temp[i];
    int x=arr[i]+getMax(arr,n,i+2,temp);
    int y=getMax(arr,n,i+1,temp);
    int output=max(x,y);
    temp[i]=output;
    return output;
    
}    



int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    int *temp=new int[n];
    for(int i=0;i<n;i++)
        temp[i]=0;
    return getMax(arr,n,0,temp);
    
}