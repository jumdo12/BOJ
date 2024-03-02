#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    int PrimeNumbers[246913]={0};

    PrimeNumbers[0]=PrimeNumbers[1]=1;
    for(int i=2; i<=246912; i++){
        if(PrimeNumbers[i]){
            continue;
        }
        for(int j = 2*i; j<=246912; j+=i){
            PrimeNumbers[j] = 1;
        }
    }

    std::cin>>N;
    while(N != 0){
        int cnt=0;
        for(int i=N+1; i<=2*N; i++){
            if(!PrimeNumbers[i])    cnt++;
        }
        std::cout<<cnt<<'\n';
        std::cin>>N;
    }

    return 0;
}