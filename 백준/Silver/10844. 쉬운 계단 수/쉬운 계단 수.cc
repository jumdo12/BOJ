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
        for(int j=0; j<10; j++){
            if(j==0)arr[i][0] = arr[i - 1][1];
            else if(j==9)arr[i][9] = arr[i - 1][8];
            else arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]);
            arr[i][j] %= 1000000000;
        }
    }

    for(int i=0; i<10; i++){
        sum = (sum + arr[N][i]) % 1000000000;
    }
    std::cout<<sum;

    return 0;
}