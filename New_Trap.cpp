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
	if(scan==1) Tra(1);

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
	bloode(-5);//Func eff
	pointed(-3);
	cout<<"The eff is -5 HP -3 point(S)"<<'\n';		
	}
	if(q == 2){
	pointed(-2);//Func eff
	//add Stop eff
	cout<<"The eff is -2 point and stop 2 turn(S)"<<'\n';
	}
	if(q == 3){
	pointed(-3);//Func eff
	//add Back to Start eff
	cout<<"Back to Start and -3 point(S)"<<'\n';
	}

}

void AEffect(int q){
	if(q == 1){
	bloode(-4);
	pointed(-2);
	cout<<"The eff is -4 HP -2 Point(A)"<<'\n';		
	}
	if(q == 2){
	pointed(-1);
	//add 3 step back
	cout<<"3 step back and -1 point(A)"<<'\n';
	}
	if(q == 3){
	bloode(-2);
	//add dice lock
	cout<<"-2 HP and dice lock(1)(A)"<<'\n';
	}

}

void BEffect(int q){
	if(q == 1){
	bloode(-2);
	pointed(-1);
	cout<<"the eff is -2 HP -1 Point(B)"<<'\n';		
	}
	if(q == 2){
	//add stop eff
	cout<<"Stop 1 turn(B)"<<'\n';
	}
	if(q == 3){
	pointed(-1);
	//add take eff x2 eff
	cout<<"- 1 Point and take effx2(B)"<<'\n';
	}

}

void CEffect(int q){
	if(q == 1){
	//add warp to closer backward warp eff 
	cout<<"warp to closer backward warp(C)"<<'\n';		
	}
	if(q == 2){
	//add move to infornt of next trap eff
	cout<<"move to infornt of next trap(C)"<<'\n';
	}
	if(q == 3){
	//add dice two times if sum>6 move backward>>sum step 
	cout<<"dice 2 times ^ ^ "<<'\n';
	}

}
