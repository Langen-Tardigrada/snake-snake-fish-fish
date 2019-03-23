#include<iostream>
#include<string>
#include <vector>
using namespace std;

void mademap(int n,int m);

string a[3][3];

int main(){
    int i=0,j=0;
    cout<<"please select map hightxlenght: ";
    cin>>i>>j;
    //ใส่ค่าให้ a ขี้เกียจใส่เอง
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            a[i][j]="  ";
        }
    }
    mademap(i,j);
    
    return 0;
}

void mademap(int n,int m){
    
    string num="01";
    for(int h=0; h<m; h++){
        cout<<"- - - - ";
    }
    cout<<endl;
    for(int k=0; k<n; k++){
                for(int i=0;i<3;i++){
                    for(int p=0;p<m;p++){
                        cout<<"|";
                        for(int j=0;j<3;j++){
                            a[1][1]=num;
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
    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2==0){
                cout<<"- - - - ";
            }else{
                for(int i=0;i<6;i++){
                    for(int j=0;j<6;j++){
                        cout<<a[i][j];
                    }
                    cout<<endl;
                }
            }
        }
    }*/
}