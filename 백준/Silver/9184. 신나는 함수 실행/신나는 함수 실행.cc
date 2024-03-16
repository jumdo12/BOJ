#include <iostream>

int main(){
    int A,B,C;
    std::cin>>A>>B>>C;

    int w[101][101][101] = {0};

    for (int a = 0; a < 101; a++){
        for(int b=0; b<101; b++){
            for(int c=0; c<101; c++){
                if(a <= 0 + 50 || b <= 0 + 50 || c <= 0 + 50){
                    w[a][b][c] = 1;
                }
                else if(a > (20 + 50) || b > (20 + 50) || c > (20 + 50)){
                    w[a][b][c] = 1048576;
                }
                else if(a<b&&b<c){
                    w[a][b][c] = w[a][b][c-1] + w[a][b-1][c-1] - w[a][b-1][c];
                }
                else{
                    w[a][b][c] = w[a-1][b][c] + w[a-1][b-1][c] + w[a-1][b][c-1] - w[a-1][b-1][c-1];
                }
            }
        }
    }

    while(A != -1 || B != -1 || C != -1){
        std::cout<<"w("<<A<<", "<<B<<", "<<C<< ") = "<< w[A+50][B+50][C+50]<<'\n';
        std::cin>>A>>B>>C;
    }
    return 0;
}