#include <iostream>

int main(){
    int Mat[102][102] = {0};
    int N,x,y,Ans=0;
    std::cin>>N;
    for(int i=0; i<N; i++){
        std::cin>>x>>y;
        for(int j=x; j < x+10; j++){
            for(int k=y; k<y+10; k++){
                Mat[j][k] = 1;
            }
        }
    }

    for(int i=0; i<102; i++){
        for(int j=0; j<102; j++){
            if(Mat[i][j])   Ans++;
        }
    }
    std::cout<< Ans;
    return 0;
}