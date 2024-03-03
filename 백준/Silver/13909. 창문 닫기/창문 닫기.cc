#include <iostream>

int main(){
    int N,cnt=0;
    std::cin>>N;

    for(int i=1; i*i<=N; i++){
        if(i*i <= N)  cnt++;
    }
    std::cout<<cnt;
    return 0;
}