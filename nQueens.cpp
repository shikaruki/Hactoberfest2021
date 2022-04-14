#include<iostream>

using namespace std;

bool isSafe(int board[][10],int i,int j,int n){

    //checking upper column
    int x = i,y=j;
    while(x>=0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
    }

    //checking left Diagonal
    x = i,y = j;
    while(x>=0 && y>=0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    //checking right diagonal
    x = i,y = j;
    while(x>=0 && y<n){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }

    return true;

}


bool solveNQueens(int board[][10],int i,int n){
    //base case
    if(i == n){
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(board[row][col] == 1){
                    cout<<"Q ";
                }
                else{
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    for(int j=0;j<n;j++){

        if(isSafe(board,i,j,n)){
            board[i][j] = 1;
            bool isNextSafe = solveNQueens(board,i+1,n);
            if(isNextSafe){
                return true;
            }
            //back track
            board[i][j] = 0;
        }
    }
    return false;
}
int main()
{

    int n;
    cin>>n;

    int board[10][10];
    //initializing
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j] = 0;
        }
    }


    solveNQueens(board,0,n);

}
