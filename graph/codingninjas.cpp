/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1
*/




bool check(vector<vector<char>> &board,int n,int m,int i,int j, string s,bool **vis)
{
    if(s.length()==0)
        return true;
    if(i<0||j<0||i>n-1||j>m-1)
        return false;
    
    
    
    int row_array[]={i-1,i,i+1};
    int col_array[]={j-1,j,j+1};
    for(int a=0;a<3;a++)
    {
        for(int b=0;b<3;b++)
            
        {
            int row=row_array[a];
            int col=col_array[b];
            if(row==i&& col==j)
                continue;
            if(row<0||col<0||row>n-1||col>m-1)
                continue;
            if(board[row][col]==s[0]&&!vis[row][col])
            {
                vis[row][col]=true;
                if(check(board,n,m,row,col,s.substr(1),vis))
                {
                    return true;
                }
                {
                    vis[row][col]=false;
                }
            }
        }
    }
    
    return false;
    
    
    
    
    
    
    
    
    return false;
}


bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    bool **vis=new bool*[n];
    for(int i=0;i<n;i++)
    {
        vis[i]=new bool[m];
        for(int j=0;j<m;j++)
        {
            vis[i][j]=false;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='C')
                
            {
             	vis[i][j]=true;   
                if(check(board,n,m,i,j,"ODINGNINJA",vis))
                {
                    return true;
                }
                vis[i][j]=false;
                
                
            }
            
            
			}
		
        }
    
    
    
    return false;
}