#include <iostream>

int Mata[101][101];
int Matb[101][101];
int res[101][101];

int main(){
    int N,M,K;
    std::cin>>N>>M;
    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            std::cin>>Mata[i][j];
        }
    }

    std::cin>>M>>K;
    for(int i=0; i<M; i++){
        for(int j=0; j<K; j++){
            std::cin>>Matb[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            for(int k=0; k<M; k++){
                res[i][j] += Mata[i][k] * Matb[k][j]; 
            }
            std::cout<<res[i][j]<<" ";
        }
        std::cout<<'\n';
    }

    return 0;
}