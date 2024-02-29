#include <iostream>

int main(){
    int N,M,Min=64;
    std::cin>>N>>M;
    char Board[60][60];

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            std::cin>>Board[i][j];
        }
    }

    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            int cnt=0;
            for(int k=i; k<i+8; k++){
                for(int l=j; l<j+8; l++){
                    if(((i+j)%2) == ((k+l)%2)){
                        if (Board[i][j] != Board[k][l]) cnt++;
                    }
                    else{
                        if (Board[i][j] == Board[k][l]) cnt++;
                    }
                }
            }
            if(cnt > 32)    cnt = 64 - cnt;
            
            if(cnt < Min)   Min = cnt;
        }
    }

    std::cout<<Min;

    return 0;
}