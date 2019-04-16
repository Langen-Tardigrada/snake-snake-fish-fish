#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<ctime>
using namespace std;

//------------------------(Grobal)
string a[3][6];
int blood=10;
int point=0;
int ice=0;
void mademap(int ,int ,int );
void update(int ,int ,int );

//-----------------------------(class&func for trap+tsure)
class Trap_Tsure{
	int number_of_trap[12];
	int number_of_tsure[12];
	string imgtrap[12];
	string imgtsure[12];
	public:
		Trap_Tsure();
		void showtrap_tsure_map();
		void showtsure_player();
		void showtrap_player();
		void list_trap();
		void list_tsure();
		void testshow();
};

Trap_Tsure::Trap_Tsure(){
	int x=41;
	for(int i=0; i<12; i++){
		if(x%10==4){
			x=x+10-3;
		}
		number_of_trap[i]=x;
		x++;
	}
	imgtrap[11]="CS3";
	imgtrap[10]="CS2";
	imgtrap[9]="CS1";
	imgtrap[8]="CA3";
	imgtrap[7]="CA2";
	imgtrap[6]="CA1";
	imgtrap[5]="CB3";
	imgtrap[4]="CB2";
	imgtrap[3]="CB1";
	imgtrap[2]="CC3";
	imgtrap[1]="CC2";
	imgtrap[0]="CC1";
	//------------------------------------------------------------------
	int y=1;
	for(int i=0; i<12; i++){
		if(y%10==4){
			y=y+10-3;
		}
		number_of_tsure[i]=y;
		y++;
	}
	
	imgtsure[11]="TS3";
	imgtsure[10]="TS2";
	imgtsure[9]="TS1";
	imgtsure[8]="TA3";
	imgtsure[7]="TA2";
	imgtsure[6]="TA1";
	imgtsure[5]="TB3";
	imgtsure[4]="TB2";
	imgtsure[3]="TB1";
	imgtsure[2]="TC3";
	imgtsure[1]="TC2";
	imgtsure[0]="TC1";
}


void Trap_Tsure::testshow(){
	cout<<endl<<"trap \n";
	for(int i=0; i<12; i++){
		cout<<number_of_trap[i]<<" "<<imgtrap[i];
		cout<<endl;
	}
	cout<<"tsure \n";
	for(int i=0; i<12; i++){
		cout<<number_of_tsure[i]<<" "<<imgtsure[i];
		cout<<endl;
	}
}



//-------------------------(Class&func for player)
class Player{
	string name;
	string collect_trap[5];
	string collect_tsure[5];
	int score;
	string character;
	string gagehp[10];
	int hp;
	int hpmax;
	bool dice_on;
	Trap_Tsure collect;
	public:
		int move;
		int roll;
		void newturn();
		void diceturn();
		void changhp(int );
		void dice();
		void totalscore();
		void choosechar();	
		void check(int );
};
 
void Player::dice(){
	if(dice_on==1){
		roll=(rand()%6)+1;
	}
	move+=roll;
}
void Player::diceturn(){
	dice_on = true;
}

void Player::newturn(){
	dice_on = false;
}

void Player::check(int a){
	if(move>a){
		move=move-a;
	}
}

//-------------------------(Class of Tsure)
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


void Tsure::bloode(int bloody){
	cout<<"Now Your HP = "<<blood+bloody<<'\n';
}
void Tsure::pointed(int pointy){
	cout<<"Now Your Point = "<<point+pointy<<'\n';
}

void Tsure::RandforEffect(int y){//Rand eff
	int z = 0;
	z=rand()%3;
	cout<<"You got "<<z<<" Eff.\n";
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
	cout<<"Treasure Class is "<<y<<'\n';

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

//--------------------------------(Class of Trap)
class Trap{
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

void Trap::bloode(int bloody){
	cout<<"HP = "<<blood+bloody<<'\n';
}
void Trap::pointed(int pointy){
	cout<<"Point = "<<point+pointy<<'\n';
}

void Trap::RandforEffect(int y){//Rand eff
	int z = 0;
	z=rand()%3+1;
	cout<<"Eff is "<<z<<'\n';
	if(y == 7){
		if(z == 1) SEffect(1);
		else if(z == 2) SEffect(2);
		else if(z == 3) SEffect(3);
	}
	if(y == 6){
		if( z == 1) AEffect(1);
		else if(z == 2) AEffect(2);
		else if(z == 3) AEffect(3);
	}
	
	if(y == 5){
		if( z == 1) BEffect(1);
		else if(z == 2) BEffect(2);
		else if(z == 3) BEffect(3);
	}
	if(y == 4){
		if( z == 1) CEffect(1);
		else if(z == 2) CEffect(2);
		else if(z == 3) CEffect(3);
	}
}

void Trap::Tra(bool x){

	int y =rand()%4+4;//Select Class S-C 
	cout<<"Trap Class is "<<y<<'\n';

	if(y == 7){//S class
		RandforEffect(7);
	}
	else if(y == 6){//A Class
		RandforEffect(6);
	}
	else if(y == 5){//B Class
		RandforEffect(5);
	}
	else if(y == 4){//C Class
		RandforEffect(4);
	}
}

void Trap::SEffect(int q){
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

void Trap::AEffect(int q){
	if(q == 3){
	bloode(-4);
	pointed(-2);
	cout<<"The eff is -4 HP -2 Point(A)"<<'\n';		
	}
	if(q == 2){
	pointed(-1);
	//add 3 step back
	cout<<"3 step back and -1 point(A)"<<'\n';
	}
	if(q == 1){
	bloode(-2);
	//add dice lock
	cout<<"-2 HP and dice lock(1)(A)"<<'\n';
	}

}

void Trap::BEffect(int q){
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

void Trap::CEffect(int q){
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


//-------------------------(main)
int main(){
	Player one;
	Player two;
    srand(time(0));
    int i=0,j=0;
    cout<<"Input heightxlenght: ";
    cin>>i>>j;
    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            a[i][j]=" ";
        }
    }
    //-------------------------------------------------------------------------(print to screen)
    one.newturn();
  	two.newturn();
  	one.move=0;
  	two.move=0;
  	one.roll=0;
  	two.roll=0;
  	char action;
  	mademap(i,j,one.roll);
   while(true){
		one.newturn();
  		two.newturn();
		cout<<"Please PlayerI choose action in your turn\npress [D] = Dice, [U] = Use item, [E] = Exit \n";
  		cout<<"Your device: ";
  		cin>>action;
  		action = toupper(action);
  		if(action == 'E'){
		  	cout<<"Your turn: exit game";
  			break;
		}else if(action == 'D'){
			cout<<"Your turn: Roll a dice\n";
			system("pause");
			one.diceturn();
  			one.dice();
    		cout<<"Your luck is: "<<one.roll<<endl;
    		one.check(i*j);
    		cout<<one.move<<endl;
    		mademap(i,j,one.move);
    		int Trap_Or_Tsure;
    		Trap_Or_Tsure=rand()%2+1;
    		Tsure scan;
    		Trap scan2;
    		if(Trap_Or_Tsure==1) scan.Tra(1);
    		if(Trap_Or_Tsure==2) scan2.Tra(1);
			system("pause");//decide Keep or Use
		}else{
			//write use item
		}	
	}
	//------------------------------------------------------------------------------- test number of trap and img
	Trap_Tsure show;
	show.testshow();
    return 0;
}



void mademap(int n,int m, int go){
    int x=0,y=1;
    int ber=0;
    int num=0;
    for(int h=0; h<m; h++){
        cout<<"- - - -";
    }
    cout<<endl;
	x=0;	
    for(int k=0; k<n; k++){ //roll for the blog.
        for(int i=0;i<3;i++){ //roll in each space.
            for(int p=0;p<m;p++){ //column for the blog.
                cout<<"|"; 
                if((go/m)==k && (go%m)==p){
                    	a[0][0]="*";
					}
				for(int j=0;j<6;j++){ //column in each space.
                   /* if(ber==go+(m*num)){
                    	a[0][0]="*";
                    }*/
					char buffer[100];
                    if(i==1 && j==3){
                        a[1][2]=itoa(x,buffer,10);//to_string can't complie on dev-c++ because gcc(11) then use like this link-->
                        //http://www.cplusplus.com/reference/cstdlib/itoa/
                        //use this--> https://fresh2refresh.com/c-programming/c-type-casting/c-itoa-function/
						a[1][3]=itoa(y,buffer,10);
                        y++;
                    }
                    else if(i==1 && j==2){// plus two digits. 00 10  20 30
                        a[1][2]=a[1][2]=itoa(x,buffer,10);
                        a[1][3]=a[1][3]=itoa(y,buffer,10); // can dismiss this line.
                    }
                    cout<<a[i][j];
                    if(y>9){
                        y=0;
                        x++;
                    }
                }
                a[0][0]=" ";
            //   	ber++;
            }
            cout<<"|";
            cout<<endl;
        }
        for(int h=0; h<m; h++){
            cout<<"- - - -";
        }
        cout<<endl;
     //   num+=2;
    }
}
