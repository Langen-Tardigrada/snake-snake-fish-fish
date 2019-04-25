#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<algorithm>
using namespace std;

//------------------------(Grobal)
string a[3][6];
int blood=10;
int point=0;
int ice=0;
 //,const vector<int> &
void update(int ,int ,int );
bool check=false;
void built_screen();
vector<int> list_item;
vector<int> Wrap;
void showlistitem(vector<int> &);
int turn=0;

//-----------------------------(class&func for trap+tsure)
class Trap_Tsure{
	int number_of_trap[12];
	int number_of_tsure[12];
	string imgtrap[12];
	string imgtsure[12];
	public:
		vector<int> showitem;
		vector<int> no_trap;
		vector<int> no_tsure;
		Trap_Tsure();
		void show_no_trap_tsure_map();
		void showtrap_tsure_map();
		void showtsure_player();//not now
		void showtrap_player();//not now
		void testshow();
		void listItem();
        void randomitem(int ,int );
};

void Trap_Tsure::listItem(){
	for(int i=0; i<showitem.size(); i++){
		::list_item.push_back(showitem[i]);
	}
}

void Trap_Tsure::show_no_trap_tsure_map(){
	cout<<endl<<"show random item\n";
	for(int i=0; i<showitem.size(); i++){
		cout<<showitem[i]<<" ";
	}
	cout<<"\nshow random trap\n";
	for(int i=0; i<no_trap.size(); i++){
		cout<<no_trap[i]<<" ";
	}
	cout<<"\nshow random tsure\n";
	for(int i=0; i<no_tsure.size(); i++){
		cout<<no_tsure[i]<<" ";
	}
}

void Trap_Tsure::randomitem(int a,int b){
    //percent to put out on map.
	int percent_put_out = (double (40.0/100.0))*a*b;
	int check,no;
	showitem.push_back(0);
	for(int i=0; i<percent_put_out; i++){
		int random = rand()%100+1;
		if(random<=40){
			no = rand()%(a*b)+1;
			check = rand()%2+1;	
			for(int j=0; j<showitem.size(); j++){
				if(no!=showitem[j]){
					if(check==1){
						showitem.insert(showitem.begin(),no);
						no_trap.push_back(no);
					}else if(check==2){
						showitem.insert(showitem.begin(),no);
						no_tsure.push_back(no);
					}
					break;
				}
			}
			sort (&showitem[0],&showitem[(showitem.size())]); //definition with template <class RandomAccessIterator> //void sort (RandomAccessIterator first, RandomAccessIterator last)
			sort (&no_trap[0],&no_trap[(no_trap.size())]);
			sort (&no_tsure[0],&no_tsure[(no_tsure.size())]);
			for(int k=1; k<showitem.size(); k++){
				if(showitem[k-1]==showitem[k]){
					if(check==1){
						for(int l=0; l<no_trap.size(); l++){
							if(no_trap[0]==showitem[k] && no_tsure[0]==showitem[k]){
								no_trap.erase(no_trap.begin());
								break;
							}else if(no_trap[l]==showitem[k]){
								no_trap.erase(no_trap.begin()+l);
								break;
							}
						}
					}else{
						for(int h=0; h<no_tsure.size(); h++){
							if(no_trap[0]==showitem[h] && no_tsure[0]==showitem[k]){
								no_tsure.erase(no_tsure.begin());
								break;
							}else if(no_tsure[h]==showitem[k]){
								no_tsure.erase(no_tsure.begin()+h);
								break;
							}
						}	
					}
					showitem.erase(showitem.begin()+k);
					i--;
				}	
			}
		}else{
			i--;
		}
	}
	showitem.erase(showitem.begin());
}

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

void Trap_Tsure::showtrap_tsure_map(){
    int a = rand()%5+1;
    if(a==5){
        check=true;
        
    }else check=false;
    
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
		void Wrap_forward(int ,int ,int ,int ,int ,int ,int ,int ,int );
		void mademap(int ,int ,int );
};
void Player::Wrap_forward(int W,int Wt,int i,int j,int n,int m,int p,int k,int go){
	//if((Wt/m==k) && (Wt%m==p)) a[0][2]="@";
	if(Wt>n*m) {
	if(((m*n/3)/m==k) && ((m*n/3)%m==p)){
					a[0][j]="@";
				}else{
					a[0][j]=" ";
				}
	/*if(((m*n/2)/m==k) && ((m*n/2)%m==p)){
					a[0][i]="@";
				}else{
					a[0][i]=" ";
				}*/
		
	}else
	if((W/m==k) && (W%m==p)){
					a[0][j]="@";
				}else{
					a[0][j]=" ";
				}
	/*if((Wt/m==k) && (Wt%m==p)){
					a[0][i]="@";
				}else{
					a[0][i]=" ";
				}*/
	
	
	if(go==W){
		if((Wt/m)==k && (Wt%m)==p){
            a[0][0]="*";
            move=move+(Wt-W)+1;

	}
	}
} 
void Player::dice(){
	if(dice_on==1){
		//roll=(rand()%6+1);
		roll=1;
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
	z=rand()%3+1;
	cout<<"You got "<<z<<" Eff.\n";
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

void Tsure::Tra(bool x){

	int y =rand()%4;//Select Class S-C 
	
	cout<<"Treasure Class is "<<(y==4? 'S': y==5? 'A' : y==6? 'B' :'C')<<'\n';

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

void Tsure::SEffect(int q){
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
	pointed(1);
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
	cout<<"Trap Class is "<<(y==4? 'S': y==5? 'A' : y==6? 'B' :'C')<<'\n';

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
	Trap_Tsure show;
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
  	show.randomitem(i,j);
  	show.listItem();
	built_screen();
  	one.mademap(i,j,one.roll);
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
    		one.mademap(i,j,one.move);
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
	show.testshow();		
	show.show_no_trap_tsure_map();
	showlistitem(list_item);
    return 0;
}

void built_screen(){
    cout<<"\tSNAKE"<<"\t\tTurn: "<<turn<<endl;
    cout<<"\tPlayer1 :name"<<"\t\t\t\t\t\t\t\t\t"<<"\t\t                    Player2 :name"<<endl;//edit name
    cout<<"\tHp:||||||||||"<<"\t\t\t\t\t\t\t\t\t"<<"\t\t                Hp:||||||||||"<<endl;//edit hp
    cout<<"TRAP             "<<"\t|"<<"\t\tTREASURE    "<<"\t\t\t\t\t\t\t\t\t        "<<"TRAP             "<<"\t|"<<"\t\tTREASURE"<<endl<<endl;
    cout<<"***TRAP's Members"<<"\t|"<<"\t\t***TREASURE's Members"<<"\t\t\t\t\t\t\t\t\t"<<"***TRAP's Members"<<"\t|"<<"\t\t***TREASURE's Members"<<endl;
}
void Player::mademap(int n,int m, int go){
	Trap_Tsure tt;
    int x=0,y=1,s=0;
    int ber=0;
    int num=0;
	bool kuy[n*m],v;
	for(int i=0;i<sizeof(kuy);i++){
        kuy[i]=false;
    }
    cout<<"\t\t\t\t\t\t\t";
    for(int h=0; h<m; h++){
        cout<<"- - - -";
    }
    cout<<endl;
	x=0;	
    for(int k=0; k<n; k++){ //roll for the blog.
        for(int i=0;i<3;i++){ //roll in each space.
			cout<<"\t\t\t\t\t\t\t";
            for(int p=0;p<m;p++){ //column for the blog.
                cout<<"|"; 
                if((go/m)==k && (go%m)==p){
                    a[0][0]="*";
				}
				if((list_item[s])/m==k && (list_item[s])%m==p){
					a[0][5]="+";
				//	v = true;
					s++;
				}else{
					a[0][5]=" ";
					//v = false;
				}
				/*if(turn%5==0){
                    tt.showtrap_tsure_map();
                if(check==true){
                        a[1][1]="+";
                        kuy[num]=1;
                    }
                if(check==false){
                        a[1][1]=" ";
                        kuy[num]=0;     
                    }
                }*/
                Wrap_forward(23,55,13,3,n,m,p,k,go);
                Wrap_forward(8,20,2,4,n,m,p,k,go);
				num++;
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
		cout<<"\t\t\t\t\t\t\t";
        for(int h=0; h<m; h++){
            cout<<"- - - -";  
        }
        cout<<endl;
     //   num+=2;
     	
    }
	turn++;

	for(int i=0;i<sizeof(kuy);i++){
        cout<<kuy[i];
    }
}


void showlistitem(vector<int> &list_item){
	cout<<"\nshow list item: ";
	for(int i=0; i<list_item.size(); i++){
		cout<<list_item[i]<<" ";
	}
}