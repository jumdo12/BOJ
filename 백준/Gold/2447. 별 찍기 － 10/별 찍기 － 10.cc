#include <iostream>
#include <cmath>
void star(int x,int y, int Num){
    if(Num == 3){
        if(x%3 == 1 && y%3 == 1){
            std::cout<<" ";
        }
        else{
            std::cout<<"*";
        }
    }
    else{
        if((x/(Num/3)%3 == 1)&&(y/(Num/3)%3) == 1)  std::cout<<" ";
        else    star(x,y,Num/3);
    }
}

int main(){
    int N;
    std::cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            star(i,j,N);
        }
        std::cout<<'\n';
    }
    return 0;
}