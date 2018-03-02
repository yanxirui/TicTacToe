#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "ChessBoard.h"
#include <iostream>

enum Role { Human, Comp };
static const int CompWin = 2;
static const int Draw = 1;
static const int HumanWin = 0;
class TicTacToe {
public:
    void start();                  //开始游戏
    void show_meun();            //显示游戏主菜单
    bool handleGameOver();         //处理游戏结束
    bool gameIsOver(bool &draw, Role &win); //游戏结束
    Role chooseFirstPlace();       //选择谁先开始
    void compPlace();              //电脑下棋
    int *getBestMove();             //获得最好位置
    void humanPlace();             //人下棋
    void getPlacePosition(int *pos);        //获得下棋位置
    void findCompMove(int *bestMove,int& value, int alpha, int beta);   //找到计算机下棋位置
    void findHumanMove(int *bestMove,int& value, int alpha, int beta);  //找到人下棋位置
private:
    ChessBoard board;
};
#endif // !TicTacToe

