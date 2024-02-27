#include <iostream>
#define Max 10002
int main(){
    int N,M,Sum=0,Min=Max,Prime_Nums[10001];
    for(int i=0; i<10001; i++){
        Prime_Nums[i] = 1;
    }
    Prime_Nums[1] = 0;
    for(int i=2; i<10001; i++){
        if(!Prime_Nums[i])  continue;
        for(int j = 2*i; j<=10001; j+=i){
            Prime_Nums[j] = 0;
        }
    }
    std::cin>>N>>M;
    for(int i=N; i<=M; i++){
        if(Prime_Nums[i]){
            Sum += i;
            if(i < Min) Min = i;
        }
    }
    if(Min == Max)  std::cout << -1;
    else{
        std::cout<<Sum<<std::endl;
        std::cout<<Min;
    }
    return 0;
}