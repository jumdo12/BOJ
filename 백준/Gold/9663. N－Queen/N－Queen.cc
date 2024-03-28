#include <iostream>

int cnt;
int N;
int cols[20];

int abs(int a){
    return a < 0 ? -a : a;
}

int check(int l){
    for(int i=0; i<l; i++){
        if(cols[i] == cols[l] || abs(cols[i] - cols[l]) == l - i){
            return 0;
        }
    }
    return 1;
}

void Nqueen(int r){
    if(r == N){
        cnt++;
    }
    else{
        for(int i=0; i<N; i++){
            cols[r] = i;
            if(check(r)){
                Nqueen(r+1);
            }
        }
    }
}

int main(){
    std::cin>>N;
    Nqueen(0);
    std::cout<<cnt;
}