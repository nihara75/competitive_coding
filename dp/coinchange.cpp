/*

Coin Change Problem

For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.
Input Format
The first line of the input contains an integer value N, which denotes the total number of denominations.

The second line of input contains N values, separated by a single space. These values denote the value of denomination.

The third line of the input contains an integer value, that denotes the value of V.
Output Format
Print the total total number of ways i.e. W
*/

int ways(int deno[],int num,int value,int **output)
    
{
    if(num==0)
        return 0;
    if(value==0)
        return 1;
    if(value<0)
        return 0;
    if(output[value][num]>-1)
        return output[value][num];
    int first=ways(deno,num,value-deno[0],output);
    int second=ways(deno+1,num-1,value,output);
    output[value][num]=first+second;
    return first+second;
}    




int countWaysToMakeChange(int denominations[], int n, int value){
	//Write your code here
    
    
    
    int **output = new int *[1001];
    for (int i = 0; i < 1001; i++)
    {
        output[i] = new int[11];
        for (int j = 0; j < 11; j++)
        {
            output[i][j] = -1;
        }
    }
    return ways(denominations,n,value,output);
}