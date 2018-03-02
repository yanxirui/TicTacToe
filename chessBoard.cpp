#include "chessBoard.h"



ChessBoard::ChessBoard()             //棋盘初始化
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            boardInOneDimens[i][j] = 0;
}
bool ChessBoard::isEmpty(int x,int y)    //判断pos位置是否为空
{
    return boardInOneDimens[x][y] == 0;
}

bool ChessBoard::isFull()            //判断当前棋盘是否满
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if (boardInOneDimens[i][j] == 0) return false;
    return true;
}

bool ChessBoard::canWin(int c)      //判断当前是否能赢
{
    int i=0;
    //check rows
    for(i=0; i<3; i++){
        if (boardInOneDimens[i][0] == c && boardInOneDimens[i][1]== c && boardInOneDimens[i][2] == c )
            return true;
    }
    //check cols
    for(i=0; i<3; i++){
        if (boardInOneDimens[0][i] == c && boardInOneDimens[1][i]== c && boardInOneDimens[2][i] == c)
            return true;
    }
    //check diagonals
    if(boardInOneDimens[0][0]==c && boardInOneDimens[1][1]==c && boardInOneDimens[2][2]==c)
        return true;
    if(boardInOneDimens[0][2]==c && boardInOneDimens[1][1]==c && boardInOneDimens[2][0]==c)
        return true;
    return false;
}
bool ChessBoard::immediateComWin(int *bestMove)     //判断这一步计算机是否能赢，并返回这一步
{
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if (isEmpty(i,j)){
                boardInOneDimens[i][j] == Comp_int;
                bool win = canWin(Comp_int);
                boardInOneDimens[i][j] = Blank_int;
                if(win){
                    bestMove[0] = i;
                    bestMove[1] = j;
                    return true;
                }
            }
        }
    }
    return false;
}
bool ChessBoard::immediateHumanWin(int *bestMove)   //判断这一步人是否能赢，并返回这一步
{
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if (isEmpty(i,j)){
                boardInOneDimens[i][j] == Human_int;
                bool win = canWin(Human_int);
                boardInOneDimens[i][j] = Blank_int;
                if(win){
                    bestMove[0] = i;
                    bestMove[1] = j;
                    return true;
                }
            }
        }
    }
    return false;
}
void ChessBoard::placeComp(int x,int y)     //计算机在pos位置下棋
{
    boardInOneDimens[x][y] = Comp_int;
}
void ChessBoard::placeHuman(int x,int y)    //人在pos位置下棋
{
    boardInOneDimens[x][y] = Human_int;
}
void ChessBoard::unPlace(int x,int y)       //在pos地方取消下棋
{
    boardInOneDimens[x][y] = Blank_int;
}
void ChessBoard::print()                    //打印棋盘
{
    system("cls");
    cout<<endl<<endl<<endl;
    cout << "   Computer:○     You:●" << endl;
    cout<<"    ----------------------- "<<endl;
    for (int i=0; i<3; i++){
        cout<<"   |   ";
        if(boardInOneDimens[i][0] == Comp_int) cout << "○" <<"  |   ";
        else if(boardInOneDimens[i][0] == Human_int) cout << "●"<<"  |   ";
        else cout << "  " <<"  |   ";
        if(boardInOneDimens[i][1] == Comp_int) cout << "○"<<"  |   ";
        else if(boardInOneDimens[i][1] == Human_int) cout << "●"<<"  |   ";
        else cout << "  " <<"  |   ";
        if(boardInOneDimens[i][2] == Comp_int) cout << "○"<<"  |"<<endl;
        else if(boardInOneDimens[i][2] == Human_int) cout << "●"<<"  |"<<endl;
        else cout << "  " <<"  |"<<endl;
        if(i!=2){ cout<<"   |-------|-------|-------|"<<endl;}
        else{cout<<"    -----------------------"<<endl;}
    }
}


