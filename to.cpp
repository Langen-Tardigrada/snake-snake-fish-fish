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
//int blood=10;
//int point=0;
int ice=0;
vector<int> list_item;
vector<int> list_trap;
vector<int> list_tsure;
void mademap(int ,int ,int); 
void update(int ,int ,int );
bool check=false;
void built_screen();
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
	for(int k=0; k<no_trap.size(); k++){
		::list_trap.push_back(no_trap[k]);
	}
	for(int l=0; l<no_tsure.size(); l++){
		::list_tsure.push_back(no_tsure[l]);
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
	public:
		//Trap store_trap;
		//Tsure store_tsure;
		Player();
		int move;
		int roll;
		void newturn();
		void diceturn();
		void changhp(int );
		void dice();
		//void totalscore();
		void choosechar();	
		void check(int );//How many is player move?
		void pointed(int );//*Point
		void bloode(int );//HP
		//----------------------------------------------------------------------Tsure
		void tsure_SEffect(int );//**Trap eff
		void tsure_AEffect(int );
		void tsure_BEffect(int );
		void tsure_CEffect(int );
		void tsure_RandforEffect(int );//***Rand eff
		void tsure_Tra(bool );//****Rand Trap Class
		//----------------------------------------------------------------------Trap
		void trap_SEffect(int );//**Trap eff
		void trap_AEffect(int );
		void trap_BEffect(int );
		void trap_CEffect(int );
		void trap_RandforEffect(int );//***Rand eff
		void trap_Tra(bool );//****Rand Trap Class
};

Player::Player(){
	score = 0; hpmax = 10; hp = 10;
}

void Player::dice(){
	if(dice_on==1){
		roll=(rand()%6+1);
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

void Player::bloode(int blood){
	hp+=blood;
	cout<<"Now Your HP = "<<hp<<'\n';
}

void Player::pointed(int point){
	score+=point;
	cout<<"Now Your Point = "<<score<<'\n';
}

//-------------------------(Tsure of class player)

void Player::tsure_RandforEffect(int y){//Rand eff
	int z = 0;
	z=rand()%3+1;
	cout<<"You got "<<z<<" Eff.\n";
	if(y == 3){
		if(z == 3) tsure_SEffect(3);
		else if(z == 2) tsure_SEffect(2);
		else if(z == 1) tsure_SEffect(1);
	}
	if(y == 2){
		if( z == 3) tsure_AEffect(3);
		else if(z == 2) tsure_AEffect(2);
		else if(z == 1) tsure_AEffect(1);
	}
	
	if(y == 1){
		if( z == 3) tsure_BEffect(3);
		else if(z == 2) tsure_BEffect(2);
		else if(z == 1) tsure_BEffect(1);
	}
	if(y == 0){
		if( z == 3) tsure_CEffect(3);
		else if(z == 2) tsure_CEffect(2);
		else if(z == 1) tsure_CEffect(1);
	}
}

void Player::tsure_Tra(bool x){

	int y =rand()%4;//Select Class S-C 
	
	cout<<"Treasure Class is "<<(y==4? 'S': y==5? 'A' : y==6? 'B' :'C')<<'\n';

	if(y == 3){//S class
		tsure_RandforEffect(3);
	}
	else if(y == 2){//A Class
		tsure_RandforEffect(2);
	}
	else if(y == 1){//B Class
		tsure_RandforEffect(1);
	}
	else if(y == 0){//C Class
		tsure_RandforEffect(0);
	}
}

void Player::tsure_SEffect(int q){
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

void Player::tsure_AEffect(int q){
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

void Player::tsure_BEffect(int q){
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

void Player::tsure_CEffect(int q){
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

//--------------------------------(Trap of class player)

void Player::trap_RandforEffect(int y){//Rand eff
	int z = 0;
	z=rand()%3+1;
	cout<<"Eff is "<<z<<'\n';
	if(y == 7){
		if(z == 1) trap_SEffect(1);
		else if(z == 2) trap_SEffect(2);
		else if(z == 3) trap_SEffect(3);
	}
	if(y == 6){
		if( z == 1) trap_AEffect(1);
		else if(z == 2) trap_AEffect(2);
		else if(z == 3) trap_AEffect(3);
	}
	
	if(y == 5){
		if( z == 1) trap_BEffect(1);
		else if(z == 2) trap_BEffect(2);
		else if(z == 3) trap_BEffect(3);
	}
	if(y == 4){
		if( z == 1) trap_CEffect(1);
		else if(z == 2) trap_CEffect(2);
		else if(z == 3) trap_CEffect(3);
	}
}

void Player::trap_Tra(bool x){

	int y =rand()%4+4;//Select Class S-C 
	cout<<"Trap Class is "<<(y==4? 'S': y==5? 'A' : y==6? 'B' :'C')<<'\n';

	if(y == 7){//S class
		trap_RandforEffect(7);
	}
	else if(y == 6){//A Class
		trap_RandforEffect(6);
	}
	else if(y == 5){//B Class
		trap_RandforEffect(5);
	}
	else if(y == 4){//C Class
		trap_RandforEffect(4);
	}
}

void Player::trap_SEffect(int q){
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

void Player::trap_AEffect(int q){
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
	//add dice lock --> last turn dice is 6. In the next turn dice is same the last time.
	cout<<"-2 HP and dice lock(1)(A)"<<'\n';
	}

}

void Player::trap_BEffect(int q){
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

void Player::trap_CEffect(int q){
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
    		for(int i=0; i<list_item.size(); i++){
    			if(one.move==list_item[i]){
    				cout<<"Player1 was get item. It's "<<list_item[i]+1<<endl;
    				for(int k=0; k<list_trap.size(); k++){
    					if(list_item[i]==list_trap[k]){
    						cout<<"Player1 get item is trap"<<endl;
    						one.trap_Tra(1);
							system("pause");//decide Keep or Use
						break;
						}
					}
					for(int l=0; l<list_tsure.size(); l++){
						if(list_item[i]==list_tsure[l]){
							cout<<"Player1 get item is tsure"<<endl;
							one.tsure_Tra(1);
							system("pause");//decide Keep or Use
						break;
						}
					}
    				break;
				}
			}
			
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

void mademap(int n,int m, int go){
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
				//	v = false;
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
				num++;
				for(int j=0;j<6;j++){ //column in each space.
                    /*if(ber==go+(m*num)){
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
       // num+=2;
     	
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
	cout<<"\nshow list trap: ";
	for(int k=0; k<list_trap.size(); k++){
		cout<<list_trap[k]<<" ";
	}
	cout<<"\nshow list tsure: ";
	for(int l=0; l<list_tsure.size(); l++){
		cout<<list_tsure[l]<<" ";
	}
}