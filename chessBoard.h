
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
    ChessBoard();             //���̳�ʼ��
    bool isEmpty(int x,int y);    //�ж�posλ���Ƿ�Ϊ��
    bool isFull();            //�жϵ�ǰ�����Ƿ��
    bool canWin(int c);      //�жϵ�ǰ�Ƿ���Ӯ,c=1 or c=-1
    bool immediateComWin(int *bestMove);      //�ж�������һ���������Ƿ���Ӯ
    bool immediateHumanWin(int *bestMove);    //�ж�������һ�������Ƿ���Ӯ
    void placeComp(int x,int y);     //�������posλ������
    void placeHuman(int x,int y);    //����posλ������
    void unPlace(int x,int y);       //��pos�ط�ȡ������
    void print();                //��ӡ����

private:
    int boardInOneDimens[3][3]; //����״̬
};


#endif // !CHESS_BOARD_H
