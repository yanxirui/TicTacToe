#include "TicTacToe.h"

void TicTacToe::start()                  //��ʼ��Ϸ
{
    show_meun();
    cout << "�Ƿ�ʼ��Ϸ����";
    int start;
    cin >> start;
    if (start==1){
        Role firstPlace = chooseFirstPlace();
        if (firstPlace == Comp) {  // Choose computer to be the first
            compPlace();
        }
        while (1) {
            system("cls");
            board.print();
            if (handleGameOver()) break;
            humanPlace();
            system("cls");
            board.print();
            if (handleGameOver()) break;
            compPlace();
        }
    }
    if(start == 0) return;

}

bool TicTacToe::handleGameOver()         //������Ϸ����
{
    bool draw = false;
    Role whoWin = Comp;
    if(gameIsOver(draw,whoWin)){
        if(draw){
            cout<<"    ***********************"<<endl<<endl;
            cout<<"          ��Ϸ������       "<<endl;
            cout<<"            ƽ�֣�         "<<endl<<endl;
            cout<<"    ***********************";
        }
        else {
                if(whoWin = Comp){
                    cout<<"    ***********************"<<endl<<endl;
                    cout<<"          ��Ϸ������       "<<endl;
                    cout<<"        ��Ŷ��������       "<<endl<<endl;
                    cout<<"    ***********************";
                }
                else if(whoWin = Human){
                cout<<"    ***********************"<<endl<<endl;
                cout<<"          ��Ϸ������       "<<endl;
                cout<<"        ��ϲ����Ӯ��       "<<endl<<endl;
                cout<<"    ***********************";
                }
        }
        return true;
    }
    else return false;
}

bool TicTacToe::gameIsOver(bool &draw, Role &win) //��Ϸ����
{
    if(board.canWin(Comp_int)){
        win = Comp;
        draw = false;
        return true;
    }
    else if(board.canWin(Human_int)){
        win = Human;
        draw = false;
        return true;
    }
    else if(board.isFull()){
        draw = true;
        return true;
    }
    else return false;
}

Role TicTacToe::chooseFirstPlace()       //ѡ��˭�ȿ�ʼ
{
    int choose;
    while (1) {
        cout << "who will place first" << endl;
        cout << "0 : human first " << endl;
        cout << "1 : computer first" << endl;
        cin >> choose;
        if (choose == 0 || choose == 1) {
            cout << endl;
            break;
        }
        else
            cout << "error,please enter again" << endl;
    }
    return (Role)choose;
}

void TicTacToe::humanPlace()             //������
{
    int pos[2];
    getPlacePosition(pos);
    board.placeHuman(pos[0],pos[1]);
}

void TicTacToe::getPlacePosition(int *pos)        //���������λ��
{
    int m, n;
    while (1) {
        cout << "   �����Ӧ���£�" <<endl;
        cout << "   1 1 | 1 2 | 1 3"<<endl;
        cout << "   2 1 | 2 2 | 2 3"<<endl;
        cout << "   3 1 | 3 2 | 3 3"<<endl;
        cout << "   �����������µ�λ�����꣺" ;
        cin >> m >> n;
        if (m < 1 || m>4 || n < 1 || n>4)
            cout << "   ����������һ�飺" ;
        else {
            if (board.isEmpty(m-1,n-1)){
                pos[0] = m-1;
                pos[1] = n-1;
                break;
            }
            else
                cout << "   ��λ�����ӣ�������һ�飺" ;
        }
    }
}

void TicTacToe::compPlace()              //��������
{
    int *bestMove = getBestMove();
    board.placeComp(bestMove[0],bestMove[1]);
    cout << "the computer choice is: " << endl;
}

int *TicTacToe::getBestMove()             //������λ��
{
    int bestMove[2] = {0,0};
    int value = 0;
    findCompMove(bestMove,value,HumanWin, CompWin);
    return bestMove;
}

 //�ҵ����������λ��
void TicTacToe::findCompMove(int *bestMove,int& value, int alpha, int beta)
{
    if (board.isFull())
        value = Draw;
    else if (board.immediateComWin(bestMove))
        value = CompWin;
    else {
        value = alpha;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3&&value < beta; j++)   //С�ڦ�ʵ�֦¼�֦
            {
                if (board.isEmpty(i,j)) {
                    board.placeComp(i,j);
                    int tmp[2] = {-1,-1}, response = -1;  // Tmp is useless
                    findHumanMove(tmp, response, value, beta);
                    board.unPlace(i,j);         //�������壬�����ظ�
                    if (response > value) {
                        value = response;
                        bestMove[0] = i;
                        bestMove[1] = j;
                    }
                }
            }
    }
}

void TicTacToe::findHumanMove(int *bestMove,int& value, int alpha, int beta)
{
    if (board.isFull())
        value=Draw;
    else if (board.immediateHumanWin(bestMove)){
        value=HumanWin;
    }
    else {
        value = beta;
        for (int i = 0; i < 3; i++){
            for(int j = 0; j < 3&&value>alpha; j++)//���ڦ�ʵ�֦���֦
            {
                if (board.isEmpty(i,j)) {
                    board.placeHuman(i,j);
                    int tmp[2] = {-1,-1}, response = -1;  // Tmp is useless
                    findCompMove(tmp, response, alpha, value);
                    board.unPlace(i,j);
                    if (response <value) {
                        value = response;
                        bestMove[0] = i;
                        bestMove[1] = j;
                    }
                }
            }
        }
    }
}

void TicTacToe::show_meun()    //��ʾ���˵�
{
    system("cls");
    cout<<endl<<endl;
    cout<<"     ************************��ӭ����һ������Ϸ************************"<<endl;
    cout<<"     *                                                                *"<<endl;
    cout<<"     * ��Ϸ����:                                                      *"<<endl;
    cout<<"     *   1.���̹��Ÿ�����                                             *"<<endl;
    cout<<"     *   2.�С��С������Խ���������������ͬ�ַ�һ��Ϊʤ��             *"<<endl;
    cout<<"     *   3.��Ϊһ���������Ϊһ��                                     *"<<endl;
    cout<<"     *                                                                *"<<endl;
    cout<<"     *                                                                *"<<endl;
    cout<<"     *             1-��ʼ��Ϸ    |   0-������Ϸ                       *"<<endl;
    cout<<"     *                                                                *"<<endl;
    cout<<"     ******************************************************************"<<endl;
}
