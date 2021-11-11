/*
Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false*/

 //Sudoku-Solver

 bool inRow(int board[][9],int row,int col,int num)
{
  for(int i=0;i<9;i++)
  {
      if(board[row][i]==num)
          return false;
  }  
    
    return true;
}

bool inCol(int board[][9],int row,int col,int num)
{
    for(int i=0;i<9;i++)
  {
      if(board[i][col]==num)
          return false;
  }  
    
    return true;
    
} 
bool inBox(int board[][9],int row,int col,int num)
{
    int rowf=row-row%3;
    int colf=col-col%3;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(board[i+rowf][j+colf]==num)
                return false;
        }
    return true;
} 

bool findEmpty(int board[][9],int &row,int &col)
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            if(board[i][j]==0)
            {
                row=i;
                col=j;
                return true;
            }
        }
    return false;
} 

bool validate(int board[][9],int row,int col,int num)
{
   if(inRow(board,row,col,num)&&inCol(board,row,col,num)&&inBox(board,row,col,num)) 
       return true;
    return false;
}    

bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
    int row,col;
    if(!findEmpty(board,row,col))
        return true;
    for(int i=1;i<=9;i++)
    {
        if(validate(board,row,col,i))
        {
            board[row][col]=i;
            if (sudokuSolver(board)) 
            return true;
            board[row][col]=0;
        }
    }
  return false;

}
