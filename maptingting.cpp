#include<iostream>
using namespace std;

void mademap(int n,int m);

int main(){
	int i=0,j=0;
	cout<<"please select map hightxlenght: ";
	cin>>i>>j;
	mademap(i,j);
	
	return 0;
}


void mademap(int n,int m){
for(int h=0; h<n; h++){
	cout<<"- - - -";
}
cout<<endl;
for(int k=0; k<m; k++){
	for(int l=0; l<3; l++){
		for(int i = 0; i<n+1; i++){
			cout<<"|";
			for(int j = 0; j<3; j++){
				cout<<"  ";
			}
		}
		cout<<endl;
		}
	for(int h=0; h<n; h++){
			cout<<"- - - -";
	}
	cout<<endl;
	}
}
