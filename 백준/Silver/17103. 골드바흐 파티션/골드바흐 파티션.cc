#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N,num,left,right,cnt;
    int PrimeNumbers[1000001] = {0};
    PrimeNumbers[0]=PrimeNumbers[1] = 1;
    for(int i=2; i<1000001; i++){
        if(PrimeNumbers[i]) continue;
        for(int j = 2*i; j<1000001; j+=i){
            PrimeNumbers[j] = 1;
        }
    }
    std::cin>>N;
    for(int i=0; i<N; i++){
        std::cin>>num;
        cnt=0;
        for(left = num/2; left >= 2; left--){
            right = num - left;
            if(!PrimeNumbers[left] && !PrimeNumbers[right]) cnt++;
        }
        std::cout<<cnt<<'\n';
    }

    return 0;
}