#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void dice();
char rand(char &);
void itemC(char );
void trapC(char );

int main()
{
	srand(time(0));
	dice();
	char item,trap;
	rand(item);
	rand(trap);

	itemC(item);
	trapC(trap);
	
}

char rand(char &obj){
	int x;
	x=rand()%100+1;
	if(x>=1 && x<=10) x=83;
	else if(x>10 && x<=30) x=65;
	else if(x>30 && x<=50) x=66;
	else x=67;
	obj=x;
	return obj;
}
void itemC(char item){
	switch(item){
		case 'S': cout << "You got S item +3 HP.\n";break;
    	case 'A': cout << "You got A item +2 HP.\n";break;
    	case 'B': cout << "You got B item +1 HP.\n";break;
    	case 'C': cout << "You got C item have other effect";
    	cout<<"\n";
	}
}
void trapC(char trap){
	switch(trap){
		case 'S': cout << "You got S item -3 HP and another eff.\n";break;
    	case 'A': cout << "You got A item -2 HP and another eff.\n";break;
    	case 'B': cout << "You got B item-1 HP and another eff.\n";break;
    	case 'C': cout << "You got C item other effect";
	}
}



void dice(){
	int x;
	x=rand()%6+1;
	cout<<"Your dice is "<<x<<"\n";
}