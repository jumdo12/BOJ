#include <iostream>

int paper[129][129];
int Bcnt;
int Wcnt;

void recv(int r, int c, int size){
    int flag = 0;
    int temp = paper[r][c];

    for(int i = r; i < r + size; i++){
        for(int j = c; j < c + size; j++){
            if(paper[i][j] != temp){
                flag = 1;
                break;
            }
        }
    }
    
    if(flag){
        recv(r,c,size/2);
        recv(r,c+size/2,size/2);
        recv(r+size/2,c,size/2);
        recv(r+size/2,c+size/2,size/2);
    }
    else{
        if(temp)    Bcnt++;
        else    Wcnt++;
    }
}

int main(){
    int N;
    std::cin>>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            std::cin>>paper[i][j];
        }
    }

    recv(0,0,N);
    std::cout<<Wcnt<<'\n'<<Bcnt;

    return 0;
}