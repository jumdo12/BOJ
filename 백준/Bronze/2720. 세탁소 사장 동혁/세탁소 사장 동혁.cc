#include <stdio.h>

void exchange(int N){
    int tmp = N;
    printf("%d ",tmp / 25);
    tmp %= 25;
    printf("%d ",tmp / 10);
    tmp %= 10;
    printf("%d ",tmp / 5);
    tmp %= 5;
    printf("%d\n",tmp);

    return;
}

int main(){
    int T,N;

    scanf("%d" , &T);

    for(int i=0; i<T; i++){
        scanf("%d" , &N);
        exchange(N);
    }

    return 0;
}