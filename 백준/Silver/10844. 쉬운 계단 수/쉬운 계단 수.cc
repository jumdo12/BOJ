#include <iostream>

int main(){
    long long arr[101][10] = {0};
    long long sum = 0;
    int N;
    
    for(int i=1; i<10; i++){
        arr[1][i] = 1;
    }
    std::cin>>N;

    for(int i=2; i<=N; i++){
        arr[i][0] = arr[i - 1][1] % 1000000000;
        arr[i][9] = arr[i - 1][8] % 1000000000;
        for(int j=1; j<=8; j++){
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % 1000000000;
        }
    }

    for(int i=0; i<10; i++){
        sum = (sum + arr[N][i]) % 1000000000;
    }
    std::cout<<sum;

    return 0;
}