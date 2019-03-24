#include<iostream>
using namespace std;

void mademap(int n,int m);

char a[3][3];

int main(){
    int i=0,j=0;
    cout<<"please select map hightxlenght: ";
    cin>>i>>j;
    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            a[i][j]=' ';
        }
    }
    mademap(i,j);
    
    return 0;
}

void mademap(int n,int m){
	int u=1;
    char x;
    for(int h=0; h<m; h++){
        cout<<"- - - - ";
    }
    cout<<endl;
    for(int k=0; k<n; k++){
                for(int i=0;i<3;i++){
                    for(int p=0;p<m;p++){
                        cout<<"|";
                        for(int j=0;j<6;j++){
                        	if(i==1){
                        		if(u/10==0){
                        			if(j==2){
                        				a[i][j]='0';
									}else if(j==3){
										x='0'+u;
										a[i][j]=x;
										u++;
									}
								}else if(u/10!=0){
                        			if(j==2){
                        				x='0'+(u/10);
                        				a[i][j]=x;
									}else if(j==3){
										x='0'+(u%10);
										a[i][j]=x;
										u++;
									}
								}
							}
                            cout<<a[i][j];
                        }
                    }
                    cout<<"|";
                    cout<<endl;
                }
        
        for(int h=0; h<m; h++){
            cout<<"- - - - ";
        }
        cout<<endl;
    }
}
