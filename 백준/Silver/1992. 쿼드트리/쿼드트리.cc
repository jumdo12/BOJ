#include <iostream>
#include <string>

int N;
int Image[64][64];

int check(int r, int c, int size){
    int tmp = Image[r][c];
    for(int i=r; i<r+size; i++){
        for(int j=c; j<c+size; j++){
            if(tmp != Image[i][j])  return 0;
        }
    }
    return 1;
}

void recv(int r, int c, int size){
    if(size == 0) return;

    if(check(r,c,size)){
        printf("%d",Image[r][c]);
    }
    else{
        printf("(");
        recv(r,c,size/2);
        recv(r,c+size/2,size/2);
        recv(r+size/2,c,size/2);
        recv(r+size/2,c+size/2,size/2);
        printf(")");
    }
}

int main(){
    std::cin>>N;
    std::string str;
    for(int i=0; i<N; i++){
        std::cin>>str;
        for(int j=0; j<N; j++){
            Image[i][j] = str[j] - '0';
        }
    }

    recv(0,0,N);

    return 0;
}