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
    void start();                  //��ʼ��Ϸ
    void show_meun();            //��ʾ��Ϸ���˵�
    bool handleGameOver();         //������Ϸ����
    bool gameIsOver(bool &draw, Role &win); //��Ϸ����
    Role chooseFirstPlace();       //ѡ��˭�ȿ�ʼ
    void compPlace();              //��������
    int *getBestMove();             //������λ��
    void humanPlace();             //������
    void getPlacePosition(int *pos);        //�������λ��
    void findCompMove(int *bestMove,int& value, int alpha, int beta);   //�ҵ����������λ��
    void findHumanMove(int *bestMove,int& value, int alpha, int beta);  //�ҵ�������λ��
private:
    ChessBoard board;
};
#endif // !TicTacToe

