#include <iostream>

int max = 1;
char a[51][51] = {0};

void SWAP(char* a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void check(int N);

int main(){
    int N;

    std::cin>>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            std::cin>>a[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j = 0; j<N-1; j++){
            SWAP(&a[i][j], &a[i][j+1]);
            check(N);
            SWAP(&a[i][j],&a[i][j+1]);
        }
    }

    for(int j=0; j<N; j++){
        for(int i = 0; i<N-1; i++){
            SWAP(&a[i][j], &a[i+1][j]);
            check(N);
            SWAP(&a[i+1][j],&a[i][j]);
        }
    }

    std::cout<<max;

    return 0;
}

void check(int N){
    int cnt;
    char ch;

    for(int i =0; i<N; i++){
        cnt = 1;
        ch = a[i][0];
        for(int j=1; j<N; j++){
            if(ch == a[i][j]){
                cnt++;
            }
            else cnt = 1;
            ch = a[i][j];
            max = (cnt > max) ? cnt : max;
        }
    }

    for (int j = 0; j < N; j++){
        cnt = 1;
        ch = a[0][j];
        for (int i = 1; i < N; i++){
            if (ch == a[i][j]){
                cnt++;
            }
            else cnt = 1;
            max = (cnt > max) ? cnt : max;
            ch = a[i][j];
        }
    }
}