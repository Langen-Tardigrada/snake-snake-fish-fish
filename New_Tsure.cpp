#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int blood=10;
int point=0;

void pointed(int );//*Point
void bloode(int );//HP
void SEffect(int );//**Trap eff
void AEffect(int );
void BEffect(int );
void CEffect(int );

void RandforEffect(int );//***Rand eff
void Tra(bool );//****Rand Trap Class

int main(){
	srand(time(0));
	int scan=1;
	if(scan==1) Tra(1);#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int blood=10;
int point=0;

void pointed(int );//*Point
void bloode(int );//HP
void SEffect(int );//**Trap eff
void AEffect(int );
void BEffect(int );
void CEffect(int );

void RandforEffect(int );//***Rand eff
void Tre(bool );//****Rand Trap Class

int main(){
	srand(time(0));
	int scan=1;
	if(scan==1) Tre(1);

}

void bloode(int bloody){
	cout<<"HP = "<<blood+bloody<<'\n';
}
void pointed(int pointy){
	cout<<"Point = "<<point+pointy<<'\n';
}

void RandforEffect(int y){//Rand eff
	int z = 0;
	z=rand()%3+1;
	cout<<"Eff is "<<z<<'\n';
	if(y == 3){
		if(z == 3) SEffect(3);
		else if(z == 2) SEffect(2);
		else if(z == 1) SEffect(1);
	}
	if(y == 2){
		if( z == 3) AEffect(3);
		else if(z == 2) AEffect(2);
		else if(z == 1) AEffect(1);
	}
	
	if(y == 1){
		if( z == 3) BEffect(3);
		else if(z == 2) BEffect(2);
		else if(z == 1) BEffect(1);
	}
	if(y == 0){
		if( z == 3) CEffect(3);
		else if(z == 2) CEffect(2);
		else if(z == 1) CEffect(1);
	}
}

void Tre(bool x){

	int y =rand()%4;//Select Class S-C 
	cout<<"Trap Class is "<<y<<'\n';

	if(y == 3){//S class
		RandforEffect(3);
	}
	else if(y == 2){//A Class
		RandforEffect(2);
	}
	else if(y == 1){//B Class
		RandforEffect(1);
	}
	else if(y == 0){//C Class
		RandforEffect(0);
	}
}

void SEffect(int q){
	if(q == 3){
	//bloode(10);//Func eff 
	pointed(3);
	cout<<"The eff is +10 HP(when die) +3 point(S)"<<'\n';		
	}
	if(q == 2){
	pointed(3);//Func eff
	//add move forward eff
	cout<<"The eff is +3 point and move forward 5 step(Active)(S)"<<'\n';
	}
	if(q == 1){
	pointed(3);//Func eff
	//add clear bad-eff
	cout<<"clear bad-effect(Active) and +3 point(S)"<<'\n';
	}

}

void AEffect(int q){
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

void BEffect(int q){
	if(q == 1){
	pointed(1);
	cout<<"the eff is +1 Point(B)"<<'\n';		
	}
	if(q == 2){
	//add -HP enimies
	pointed(1);
	cout<<"-1 HP enimies(Active)(B)"<<'\n';
	}
	if(q == 3){
	pointed(1);
	//add dice 2 times if first dice= second dice move forward along to the dice
	cout<<"dice 2 times(Active)(B)"<<'\n';
	}

}

void CEffect(int q){
	if(q == 1){
	//add Go to warp point eff 
	cout<<"Go to closest warp point(C)"<<'\n';		
	}
	if(q == 2){
	//add move forward 1 step eff
	cout<<"move forward 1 step(C)"<<'\n';
	}
	if(q == 3){
	//add Barries eff
	cout<<"Get 1 Barrie"<<'\n';
	}

}


}

void bloode(int bloody){
	cout<<"HP = "<<blood+bloody<<'\n';
}
void pointed(int pointy){
	cout<<"Point = "<<point+pointy<<'\n';
}

void RandforEffect(int y){//Rand eff
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

void Tra(bool x){

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

void SEffect(int q){
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

void AEffect(int q){
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

void BEffect(int q){
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

void CEffect(int q){
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
