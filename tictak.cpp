#include <iostream>
#include <stdlib.h>


using std::cout;
using std::cin;
using std::endl;

int arr[9]={1,2,3,4,5,6,7,8,9};
int end=0,count=0;

void play(char x,char e[3][3],char c,int player);
void disp_board(char e[3][3],int player );


void draw(char e[3][3])
{
	system("cls");
	cout<<"\n";
	
 cout<<"\t ZERO KATA\n";
 cout<<"\n";
 cout<<"\n";	
	cout<<"\t      |      |      "<<endl ;
	cout<<"\t  "<<e[0][0]<<"   |  "<<e[0][1]<<"   |  "<<e[0][2]<<"   "<< endl;
	cout<<"\t______|______|______"<< endl;
	cout<<"\t      |      |      "<< endl;
	cout<<"\t  "<<e[1][0]<<"   |  "<<e[1][1]<<"   |  "<<e[1][2]<<"   "<< endl;
	cout<<"\t______|______|______"<< endl;
	cout<<"\t      |      |      "<< endl;
	cout<<"\t  "<<e[2][0]<<"   |  "<<e[2][1]<<"   |  "<<e[2][2]<<"   "<< endl;
	cout<<"\t      |      |      "<< endl;

			cout <<"\t \n";
		cout <<"\t \n";
		cout <<"\t IT's A DRAW \n";
		end=1;
		

}
void declare(int p,char e[3][3])
{
	system("cls");
	cout<<"\n";
	
 cout<<"\t ZERO KATA\n";
 cout<<"\n";
 cout<<"\n";	
	cout<<"\t      |      |      "<<endl ;
	cout<<"\t  "<<e[0][0]<<"   |  "<<e[0][1]<<"   |  "<<e[0][2]<<"   "<< endl;
	cout<<"\t______|______|______"<< endl;
	cout<<"\t      |      |      "<< endl;
	cout<<"\t  "<<e[1][0]<<"   |  "<<e[1][1]<<"   |  "<<e[1][2]<<"   "<< endl;
	cout<<"\t______|______|______"<< endl;
	cout<<"\t      |      |      "<< endl;
	cout<<"\t  "<<e[2][0]<<"   |  "<<e[2][1]<<"   |  "<<e[2][2]<<"   "<< endl;
	cout<<"\t      |      |      "<< endl;

			cout <<"\t \n";
		cout <<"\t \n";
		cout <<"\tPlayer "<<p<<" is the winner\n";
		end=1;
		

}



void check_win(int p,char e[3][3])
{
	if (end==1)return;
	if((e[0][0]==e[0][1] && e[0][1]==e[0][2]) 
	|| (e[1][0]==e[1][1] && e[1][1]==e[1][2])
	 || (e[2][0]==e[2][1] && e[2][1]==e[2][2] )
	 || (e[0][0]==e[1][0] && e[1][0]==e[2][0] )
	 || (e[0][1]==e[1][1] && e[1][1]==e[2][1])
	  || (e[0][2]==e[1][2] && e[1][2]==e[2][2] )
	  || (e[0][0]==e[1][1] && e[1][1]==e[2][2] )
	  || (e[0][2]==e[1][1] && e[1][1]==e[2][0]))
	{
		declare(p,e);
	}
	else
	if(count==9)
	{
		draw(e);
	}
	
	
	return;
}



void check_input(int e,char ele[3][3],int p)
{
	if (end==1)return;
	if(arr[e-1]!=0)
	{
	 arr[e-1]=0;
	 count++;
	 return;
	}
	char k;
	
	cout <<"\t \n";
	cout <<"\t \n";
	cout <<"\t "<<e<<"  is ALREADY MARKED \n";
	cout <<"\t \n";
	cout <<"\t press 'K' to continue \n";
	cin>> k; 
	disp_board(ele,p);
}






void disp_board(char e[3][3],int player )
{
if (end==1)return;	
	system("cls");
	char in;
	char c;
	cout<<"\n";
	
 cout<<"\t ZERO KATA\n";
 cout<<"\n";
 cout<<"\n";	
	cout<<"\t      |      |      "<<endl ;
	cout<<"\t  "<<e[0][0]<<"   |  "<<e[0][1]<<"   |  "<<e[0][2]<<"   "<< endl;
	cout<<"\t______|______|______"<< endl;
	cout<<"\t      |      |      "<< endl;
	cout<<"\t  "<<e[1][0]<<"   |  "<<e[1][1]<<"   |  "<<e[1][2]<<"   "<< endl;
	cout<<"\t______|______|______"<< endl;
	cout<<"\t      |      |      "<< endl;
	cout<<"\t  "<<e[2][0]<<"   |  "<<e[2][1]<<"   |  "<<e[2][2]<<"   "<< endl;
	cout<<"\t      |      |      "<< endl;

	cout<<"Player"<<player<<"'s turn\n";
		cout<<"give input\n";
	cin >> in;
	check_input(in-'0',e,player);
	play(in,e,c,player);
}



void play(char x,char e[3][3],char c,int player )
{
	if (end==1)return;
	player==1 ? c='X':c='O';
	
	if(x=='1')e[0][0]=c;
	if(x=='2')e[0][1]=c;
	if(x=='3')e[0][2]=c;
	if(x=='4')e[1][0]=c;
	if(x=='5')e[1][1]=c;
	if(x=='6')e[1][2]=c;
	if(x=='7')e[2][0]=c;
	if(x=='8')e[2][1]=c;
	if(x=='9')e[2][2]=c;
	check_win(player,e);
	player==1 ?player=2:player=1;
	disp_board(e,player);
}



int main() 
{
	int player=1;
	char ele[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	disp_board(ele,player);
	return 0;
}
