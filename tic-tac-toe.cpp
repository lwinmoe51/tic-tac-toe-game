#include<iostream>
using namespace std;

char turn;
char playerX = 'X';
char playerO = 'O';
int slot = 0;
char quit;

bool systemBreak = false; //false for continue
                  //true for break


char OX[3][3] = {
                    {' ',' ',' '},
                    {' ',' ',' '},
                    {' ',' ',' '}
                };


void chooseSlot(char turn){
    cout<<"======================================"<<endl;
    cout<<"This is player "<<turn<<" turn."<<endl;
    cout<<"Slot Index"<<endl;

    cout<<' '<<'1'<<' '<<'|'<<' '<<'2'<<' '<<'|'<<' '<<'3'<<' '<<endl;
    cout<<"---+---+---"<<endl;
    cout<<' '<<'4'<<' '<<'|'<<' '<<'5'<<' '<<'|'<<' '<<'6'<<' '<<endl;
    cout<<"---+---+---"<<endl;
    cout<<' '<<'7'<<' '<<'|'<<' '<<'8'<<' '<<'|'<<' '<<'9'<<' '<<endl;

    cout<<"Enter your slot number(1-9) : ";
    cin>>slot;
}

//draw game board
void drawBoard(char player, int position){
    
    switch (position)
    {
    case 1:
        OX[0][0] = player;
        break;

    case 2:
        OX[0][1] = player;
        break;

    case 3:
        OX[0][2] = player;
        break;

    case 4:
        OX[1][0] = player;
        break;

    case 5:
        OX[1][1] = player;
        break;

    case 6:
        OX[1][2] = player;
        break;

    case 7:
        OX[2][0] = player;
        break;

    case 8:
        OX[2][1] = player;
        break;

    case 9:
        OX[2][2] = player;
        break;
    
    default:
        break;
    }
    
    cout<<' '<<OX[0][0]<<' '<<'|'<<' '<<OX[0][1]<<' '<<'|'<<' '<<OX[0][2]<<' '<<endl;
    cout<<"---+---+---"<<endl;
    cout<<' '<<OX[1][0]<<' '<<'|'<<' '<<OX[1][1]<<' '<<'|'<<' '<<OX[1][2]<<' '<<endl;
    cout<<"---+---+---"<<endl;
    cout<<' '<<OX[2][0]<<' '<<'|'<<' '<<OX[2][1]<<' '<<'|'<<' '<<OX[2][2]<<' '<<endl;

    cout<<"======================================"<<endl;
}

void checkTurn(char previousTurn){
    if(previousTurn == 'O'){
        turn = 'X';
    }else if(previousTurn == 'X'){
        turn = 'O';
    }
}

int checkWinner(){
    //row check
    if((OX[0][0] == 'O' && OX[0][1] == 'O' && OX[0][2] == 'O')||
       (OX[1][0] == 'O' && OX[1][1] == 'O' && OX[1][2] == 'O')||
       (OX[2][0] == 'O' && OX[2][1] == 'O' && OX[2][2] == 'O')||
    //colum check
       (OX[0][0] == 'O' && OX[1][0] == 'O' && OX[2][0] == 'O')||
       (OX[0][1] == 'O' && OX[1][1] == 'O' && OX[2][1] == 'O')||
       (OX[0][2] == 'O' && OX[1][2] == 'O' && OX[2][2] == 'O')||
    //diagonal check
       (OX[0][0] == 'O' && OX[1][1] == 'O' && OX[2][2] == 'O')||
       (OX[0][2] == 'O' && OX[1][1] == 'O' && OX[2][0] == 'O')
    ){cout<<"The Winner is playerO"<<endl;
      systemBreak = true;
     }

    //row check
    if((OX[0][0] == 'X' && OX[0][1] == 'X' && OX[0][2] == 'X')||
       (OX[1][0] == 'X' && OX[1][1] == 'X' && OX[1][2] == 'X')||
       (OX[2][0] == 'X' && OX[2][1] == 'X' && OX[2][2] == 'X')||
    //colum check
       (OX[0][0] == 'X' && OX[1][0] == 'X' && OX[2][0] == 'X')||
       (OX[0][1] == 'X' && OX[1][1] == 'X' && OX[2][1] == 'X')||
       (OX[0][2] == 'X' && OX[1][2] == 'X' && OX[2][2] == 'X')||
    //diagonal check
       (OX[0][0] == 'X' && OX[1][1] == 'X' && OX[2][2] == 'X')||
       (OX[0][2] == 'X' && OX[1][1] == 'X' && OX[2][0] == 'X')
    ){cout<<"The Winner is playerX"<<endl;
      systemBreak = true;
     }else{
        cout<<"there is no winner"<<endl;
    }


}

int main(){
    cout<<"Enter first turn (X or O?) : ";
    cin>>turn;
    while(1){
        chooseSlot(turn);
        drawBoard(turn,slot);
        checkTurn(turn);
        checkWinner();
        cout<<"Do you want quit the game?(Y/N) : ";
        cin>>quit;
        if(quit == 'Y' || systemBreak == true){
            break;
        }
    }
    
    return 0;
}