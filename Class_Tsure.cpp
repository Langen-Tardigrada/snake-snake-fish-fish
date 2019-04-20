#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

		int blood=10;
		int point=0;

class Tsure{
	public:
		void pointed(int );//*Point
		void bloode(int );//HP
		void SEffect(int );//**Trap eff
		void AEffect(int );
		void BEffect(int );
		void CEffect(int );
		
		void RandforEffect(int );//***Rand eff
		void Tra(bool );//****Rand Trap Class
};

int main()
{
	srand(time(0));
	Tsure scan;
	scan.Tra(1);
	
}

/*void Tsure::bloode(int bloody){
	cout<<"HP = "<<blood+bloody<<'\n';
}

void Tsure::pointed(int pointy){
	cout<<"Point = "<<point+pointy<<'\n';
}

void */
void Tsure::bloode(int bloody){
	cout<<"HP = "<<blood+bloody<<'\n';
}
void Tsure::pointed(int pointy){
	cout<<"Point = "<<point+pointy<<'\n';
}

void Tsure::RandforEffect(int y){//Rand eff
	int z = 0;
	z=rand()%3;
	cout<<"Eff is "<<z<<'\n';
	if(y == 4){
		if(z == 0) SEffect(1);
		else if(z == 1) SEffect(2);
		else if(z == 2) SEffect(3);
	}
	if(y == 5){
		if( z == 0) AEffect(1);
		else if(z == 1) AEffect(2);
		else if(z == 2) AEffect(3);
	}
	
	if(y == 6){
		if( z == 0) BEffect(1);
		else if(z == 1) BEffect(2);
		else if(z == 2) BEffect(3);
	}
	if(y == 7){
		if( z == 0) CEffect(1);
		else if(z == 1) CEffect(2);
		else if(z == 2) CEffect(3);
	}
}

void Tsure::Tra(bool x){

	int y =rand()%4+4;//Select Class S-C 
	cout<<"Trap Class is "<<y<<'\n';

	if(y == 4){//S class
		RandforEffect(4);
	}
	else if(y == 5){//A Class
		RandforEffect(5);
	}
	else if(y == 6){//B Class
		RandforEffect(6);
	}
	else if(y == 7){//C Class
		RandforEffect(7);
	}
}

void Tsure::SEffect(int q){
	if(q == 1){
	//bloode(10);//Func eff 
	pointed(3);
	cout<<"The eff is +10 HP(when die) +3 point(S)"<<'\n';		
	}
	if(q == 2){
	pointed(3);//Func eff
	//add move forward eff
	cout<<"The eff is +3 point and move forward 5 step(Active)(S)"<<'\n';
	}
	if(q == 3){
	pointed(3);//Func eff
	//add clear bad-eff
	cout<<"clear bad-effect(Active) and +3 point(S)"<<'\n';
	}

}

void Tsure::AEffect(int q){
	if(q == 1){
	pointed(2);
	//add dice 1 more time
	cout<<"The eff is dice 1 more time(Active) and +2 Point(A)"<<'\n';		
	}
	if(q == 2){
	pointed(2);
	//add stop enimies
	cout<<"stop enimies(Active) and +2 point(A)"<<'\n';
	}
	if(q == 3){
	bloode(2);
	//if full HP get 2 point instate
	cout<<"+2 HP (+2 point when HP is full)(A)"<<'\n';
	}

}

void Tsure::BEffect(int q){
	if(q == 1){
	pointed(1);
	cout<<"the eff is +1 Point(B)"<<'\n';		
	}
	if(q == 2){
	//add -HP enimies
	cout<<"-1 HP enimies(Active)(B)"<<'\n';
	}
	if(q == 3){
	pointed(-1);
	//add dice 2 times if first dice= second dice move forward along to the dice
	cout<<"dice 2 times(Active)(B)"<<'\n';
	}

}

void Tsure::CEffect(int q){
	if(q == 1){
	//add Go to warp point eff 
	cout<<"Go to closest warp point(C)"<<'\n';		
	}
	if(q == 2){
	//add move forward 1 step eff
	cout<<"move forward 1 step(Active)(C)"<<'\n';
	}
	if(q == 3){
	//add Barries eff
	cout<<"Get 1 Barrie"<<'\n';
	}

}
