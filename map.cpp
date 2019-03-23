#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void drawsqr(int x,int y){
	int a=2;
	for(int j=0;j<y;j++){
		
		for(int i=0;i<x;i++){
			if(i==0 || i==x-1){
			
				cout<<"|";
			}else if((i==1 ||i==2) && j%2==0){
				cout<<" ";
			}else if((i==x-3 || i==x-2)&& j%2 != 0){
				cout<<" ";
			}
			else{
				cout<<"-";
			}
		}
		cout<<endl;
	}
}

int main(){
	for(int i=0;i<20;i++){
		cout<<"*";
	}
	cout<<endl;
	drawsqr(100,50);
	
	
	
	
	return 0;
}