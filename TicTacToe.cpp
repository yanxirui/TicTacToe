#include "TicTacToe.h"

void TicTacToe::start()                  //开始游戏
{
    show_meun();
    cout << "是否开始游戏？：";
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

bool TicTacToe::handleGameOver()         //处理游戏结束
{
    bool draw = false;
    Role whoWin = Comp;
    if(gameIsOver(draw,whoWin)){
        if(draw){
            cout<<"    ***********************"<<endl<<endl;
            cout<<"          游戏结束！       "<<endl;
            cout<<"            平局！         "<<endl<<endl;
            cout<<"    ***********************";
        }
        else {
                if(whoWin = Comp){
                    cout<<"    ***********************"<<endl<<endl;
                    cout<<"          游戏结束！       "<<endl;
                    cout<<"        啊哦，你输了       "<<endl<<endl;
                    cout<<"    ***********************";
                }
                else if(whoWin = Human){
                cout<<"    ***********************"<<endl<<endl;
                cout<<"          游戏结束！       "<<endl;
                cout<<"        恭喜，你赢了       "<<endl<<endl;
                cout<<"    ***********************";
                }
        }
        return true;
    }
    else return false;
}

bool TicTacToe::gameIsOver(bool &draw, Role &win) //游戏结束
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

Role TicTacToe::chooseFirstPlace()       //选择谁先开始
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

void TicTacToe::humanPlace()             //人下棋
{
    int pos[2];
    getPlacePosition(pos);
    board.placeHuman(pos[0],pos[1]);
}

void TicTacToe::getPlacePosition(int *pos)        //获得人下棋位置
{
    int m, n;
    while (1) {
        cout << "   坐标对应如下：" <<endl;
        cout << "   1 1 | 1 2 | 1 3"<<endl;
        cout << "   2 1 | 2 2 | 2 3"<<endl;
        cout << "   3 1 | 3 2 | 3 3"<<endl;
        cout << "   请输入你想下的位置坐标：" ;
        cin >> m >> n;
        if (m < 1 || m>4 || n < 1 || n>4)
            cout << "   错误，请再输一遍：" ;
        else {
            if (board.isEmpty(m-1,n-1)){
                pos[0] = m-1;
                pos[1] = n-1;
                break;
            }
            else
                cout << "   该位置有子，请再输一遍：" ;
        }
    }
}

void TicTacToe::compPlace()              //电脑下棋
{
    int *bestMove = getBestMove();
    board.placeComp(bestMove[0],bestMove[1]);
    cout << "the computer choice is: " << endl;
}

int *TicTacToe::getBestMove()             //获得最好位置
{
    int bestMove[2] = {0,0};
    int value = 0;
    findCompMove(bestMove,value,HumanWin, CompWin);
    return bestMove;
}

 //找到计算机下棋位置
void TicTacToe::findCompMove(int *bestMove,int& value, int alpha, int beta)
{
    if (board.isFull())
        value = Draw;
    else if (board.immediateComWin(bestMove))
        value = CompWin;
    else {
        value = alpha;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3&&value < beta; j++)   //小于β实现β剪枝
            {
                if (board.isEmpty(i,j)) {
                    board.placeComp(i,j);
                    int tmp[2] = {-1,-1}, response = -1;  // Tmp is useless
                    findHumanMove(tmp, response, value, beta);
                    board.unPlace(i,j);         //撤回下棋，避免重复
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
            for(int j = 0; j < 3&&value>alpha; j++)//大于α实现α剪枝
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

void TicTacToe::show_meun()    //显示主菜单
{
    system("cls");
    cout<<endl<<endl;
    cout<<"     ************************欢迎进入一字棋游戏************************"<<endl;
    cout<<"     *                                                                *"<<endl;
    cout<<"     * 游戏规则:                                                      *"<<endl;
    cout<<"     *   1.棋盘共九个方格                                             *"<<endl;
    cout<<"     *   2.行、列、或两对角线有连续三个相同字符一方为胜方             *"<<endl;
    cout<<"     *   3.人为一方，计算机为一方                                     *"<<endl;
    cout<<"     *                                                                *"<<endl;
    cout<<"     *                                                                *"<<endl;
    cout<<"     *             1-开始游戏    |   0-结束游戏                       *"<<endl;
    cout<<"     *                                                                *"<<endl;
    cout<<"     ******************************************************************"<<endl;
}
