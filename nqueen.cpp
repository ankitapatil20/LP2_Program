#include <iostream>
#define N 4
using namespace std;
void printBoard(int board[N][N])
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
           
        }
        cout<<"\n";
    }
}
bool isSafe(int board[N][N],int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i])
        return false;
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
        return false;
    }
    for(int i=row,j=col;j>=0 && i<N;j--,i++)
    {
        if(board[i][j])
        return false;
    }
    return true;
}
bool solveNQUtil(int board[N][N],int col)
{
    if(col>=N)
    return true;
    for(int i=0;i<N;i++)
    {
        if(isSafe(board,i,col))
        {
            board[i][col]=1;
            if(solveNQUtil(board,col+1)==true)
            return true;
            board[i][col]=0;
        }
    }
    return false;
}
bool solveNQ()
{
    int board[N][N]={0};
    if(solveNQUtil(board,0)==false){
        cout<<"Solution does not exist"<<endl;
        return false;
    }
    printBoard(board);
    return true;
   
}
int main()
{
    //int N;
    //cout<<"Enter number of queens : ";
    //cin>>N;
    solveNQ();

    return 0;
}
