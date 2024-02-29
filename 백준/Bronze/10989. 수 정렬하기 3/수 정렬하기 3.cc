#include <iostream>

int main(){
    int Numbers[10001]={0};
    int N;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin>>N;
    for(int i=0; i<N; i++){
        int Num;
        std::cin>>Num;
        Numbers[Num]++;
    }
    for(int i=1; i<10001; i++){
        for(int j=Numbers[i]; j>0; j--){
            std::cout<<i<<'\n';
        }
    }
    return 0;
}