#include <iostream>

int N;
int paper[2187][2187] = {0};

int zero;
int ones;
int mones;

int check(int r, int c, int size){
    int temp = paper[r][c];
    for(int i = r; i < r + size; i++){
        for(int j = c; j < c + size; j++){
            if(temp != paper[i][j]) return 0;
        }
    }
    return 1;
}

void recv(int r, int c, int size){
    if(check(r,c,size)){
        if(paper[r][c] == 0)    zero++;
        else if(paper[r][c] == 1) ones++;
        else    mones++;
    }
    else{
        for(int i = 0; i < size; i += (size / 3)){
            for(int j = 0; j < size; j += (size / 3)){
                recv(r+i,c+j,size/3);
            }
        }
    }
}

int main(){
    std::cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            std::cin>>paper[i][j];
        }
    }

    recv(0,0,N);

    std::cout<<mones<<'\n'<<zero<<'\n'<<ones;
    return 0;
}