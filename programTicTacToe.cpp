#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;

char mark = 'X';
char box[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
int count=0,gameMode;
bool gameOver=false,playerOneTurn=true;

int randomNumber()
{
	return rand()%9 + 1;
}

void gameIntro()
{
	cout<<"\n\t\t _______    _____      _______        _____      _______  _____   _____"<<std::endl;
	cout<<"\t\t    |    | |              |     /\\   |              |    |     | | "<<std::endl;
	cout<<"\t\t    |    | |       --     |    /--\\  |       --     |    |     | |----"<<std::endl;
	cout<<"\t\t    |    | |_____         |   /    \\ |_____         |    |_____| |_____"<<std::endl;
	cout<<"\n How to play : \n\n To Mark your option press respective number given in each slot of the Board (Tip : Use Numpad) \n"<<std::endl;
	cout<<"       |       |       "<<std::endl;
	cout<<"   7   |   8   |   9   "<<std::endl;
	cout<<"_______|_______|_______"<<std::endl;
	cout<<"       |       |       "<<std::endl;
	cout<<"   4   |   5   |   6   "<<std::endl;
	cout<<"_______|_______|_______"<<std::endl;
	cout<<"       |       |       "<<std::endl;
	cout<<"   1   |   2   |   3   "<<std::endl;
	cout<<"       |       |       "<<std::endl;
}

void boardRefresh()
{
	int i;
	for(i=0;i<10;i++)
	{
		box[i]=' ';
	}
}

void boardDisplay()
{
	system("cls"); //Use of system("cls") is not recomended as it gives program admin privilage.
	cout<<"       |       |       "<<std::endl;
	cout<<"   "<<box[7]<<"   |   "<<box[8]<<"   |   "<<box[9]<<"   "<<std::endl;
	cout<<"_______|_______|_______"<<std::endl;
	cout<<"       |       |       "<<std::endl;
	cout<<"   "<<box[4]<<"   |   "<<box[5]<<"   |   "<<box[6]<<"   "<<std::endl;
	cout<<"_______|_______|_______"<<std::endl;
	cout<<"       |       |       "<<std::endl;
	cout<<"   "<<box[1]<<"   |   "<<box[2]<<"   |   "<<box[3]<<"   "<<std::endl;
	cout<<"       |       |       "<<std::endl;
}

void result(char gameDecision)
{
	if(gameDecision == 'D')
	{
		cout<<"\n Draw !!"<<std::endl;
	    gameOver = true;
	}
	else if(gameDecision == 'W')
	{
		cout<<"\n "<<mark<<"\a is winner !!"<<std::endl;
	    gameOver = true;
	}
}

void gameLogic()
{
	if(box[1]==mark&&box[2]==mark&&box[3]==mark)
		result('W');
	else if(box[4]==mark&&box[5]==mark&&box[6]==mark)
		result('W');
	else if(box[7]==mark&&box[8]==mark&&box[9]==mark)
		result('W');
	else if(box[1]==mark&&box[4]==mark&&box[7]==mark)
		result('W');
	else if(box[2]==mark&&box[5]==mark&&box[8]==mark)
		result('W');
	else if(box[3]==mark&&box[6]==mark&&box[9]==mark)
		result('W');
	else if(box[1]==mark&&box[5]==mark&&box[9]==mark)
		result('W');
	else if(box[3]==mark&&box[5]==mark&&box[7]==mark)
		result('W');
	else if(count==9)
		result('D');
}

void assignMark(int choice)
{
	if(choice==1)
		box[1]=mark;
	else if(choice==2)
		box[2]=mark;
	else if(choice==3)
		box[3]=mark;
	else if(choice==4)
		box[4]=mark;
	else if(choice==5)
		box[5]=mark;
	else if(choice==6)
		box[6]=mark;
	else if(choice==7)
		box[7]=mark;
	else if(choice==8)
		box[8]=mark;
	else if(choice==9)
		box[9]=mark;
}

int input()
{
	switch(_getch())
	{
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default : return 0;
	}
}

void ticTacToe()
{
	int choice;

	if(playerOneTurn==true)
	{
		cout<<"\n Enter player "<<mark<<" : ";
		choice=input();
	}
	else
	{
		if(gameMode==1)
		{
			cout<<"\n Enter player "<<mark<<" : ";
		    choice=input();
		}
		else
		{
			cout<<"\n Computer's Turn "<<mark<<" : ";
			choice=randomNumber();
		}
	}

	cout<<"\n"<<std::endl;

	if(box[choice]==' '&&choice!=0)
	{
		count++;
		assignMark(choice);
		boardDisplay();
		gameLogic();
        if(playerOneTurn==true)
        {
        	playerOneTurn=false;
        	mark='O';
        }
        else
        {
        	playerOneTurn=true;
        	mark='X';
        }
	}
}

int main()
{
	bool gameMenu = true;
	srand(time(NULL));

	gameIntro();

	while(gameMenu)
	{
		cout<<"\n\n Select Game Mode : \n\n 1. Player Vs Player (Press 1) \n 2. Computer Vs Player (Press 2) \n\n Exit Game (Press 3) \n\n Enter Choice : ";
	    cin>>gameMode;

	    if(gameMode==1||gameMode==2)
	    {
	    	while(!gameOver)
	    	{
	    		ticTacToe();
	    	}
	    	boardRefresh();
	    	mark='X';
	    	count=0;
	    	gameOver=false;
	    	playerOneTurn=true;

	    }
	    else if(gameMode==3)
	    {
	    	cout<<"\n Thanks For Playing :)";
	    	break;
	    }
	    else
	    	cout<<"\n Invalid Input !!";
	}
	_getch();
	
	return 0;
}