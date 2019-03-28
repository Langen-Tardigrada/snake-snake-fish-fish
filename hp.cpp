#include<iostream>
#include<string>
using namespace std;

int gage_bloodP1 = 10;
char hparr[10]={};
bool result_lifeplayer1=0;
void showblood(const char hparr[]);
void updateblood(char hparr[],int hp, int &gage_bloodP1,bool &result_lifeplayer1);

int main(){
	int hp;
	cin>>hp;
	updateblood(hparr,hp,gage_bloodP1,result_lifeplayer1);
	showblood(hparr);
	if(result_lifeplayer1==0){
		cout<<"Gameover"<<endl;
	}else{
		cout<<"Alive"<<endl;
	}
	cout<<gage_bloodP1<<endl;
	
	return 0;
}

void showblood(const char hparr[10]){
	cout<<"____________"<<endl<<"| ";
	for(int i=0; i<10; i++){
		cout<<hparr[i];
	}
	cout<<" |"<<endl<<"____________"<<endl;	
}

void updateblood(char hparr[],int hp, int &gage_bloodP1, bool &result_lifeplayer1){
	if(hp>0){//if player gets +hp. gagehp will be increased.
		if(gage_bloodP1==10){//if gagehp have 10, don't change hp.
			gage_bloodP1=10;
		}else if(gage_bloodP1<10){// if gagehp have some amount that less than 10. gagehp will increased.  
			gage_bloodP1+=hp;
			if(gage_bloodP1>10){//if gagehp(was increased) have amount more than 10,gagehp will be haved 10.
				int overlife = gage_bloodP1;
				gage_bloodP1 -=(overlife-10);
			} }
	}else if(hp<0){//if player gets -hp. gagehp will be decreased.
		if(gage_bloodP1<=10 and gage_bloodP1>0){//if gagehp have 1-10. Gagehp will be decreased.
			gage_bloodP1-=hp;
			if(gage_bloodP1==0){//if gagehp(was decreased) have 0 --> Gameover.
				result_lifeplayer1 = 1;
			} } }
	for(int i=0; i<=10; i++){// store gagehp in image.
		if(i==10){
			hparr[i]='\0';
		}
		if(i<gage_bloodP1){
			 hparr[i]='I';
		}else{
			hparr[i]=' ';
		}
	}
}


