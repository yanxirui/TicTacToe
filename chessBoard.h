
#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include"windows.h"

#include <iostream>
using namespace std;

//const int ChessBoard_Row = 13;
//const int ChessBoard_Col = 26;
const int GridNuber = 9;
const int Comp_int = 1;
const int Human_int = -1;
const int Blank_int = 0;

class ChessBoard {
public:
    ChessBoard();             //棋盘初始化
    bool isEmpty(int x,int y);    //判断pos位置是否为空
    bool isFull();            //判断当前棋盘是否空
    bool canWin(int c);      //判断当前是否能赢,c=1 or c=-1
    bool immediateComWin(int *bestMove);      //判断下了这一步后计算机是否能赢
    bool immediateHumanWin(int *bestMove);    //判断下了这一步后人是否能赢
    void placeComp(int x,int y);     //计算机在pos位置下棋
    void placeHuman(int x,int y);    //人在pos位置下棋
    void unPlace(int x,int y);       //在pos地方取消下棋
    void print();                //打印棋盘

private:
    int boardInOneDimens[3][3]; //棋盘状态
};


#endif // !CHESS_BOARD_H
