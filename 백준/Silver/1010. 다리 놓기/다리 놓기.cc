#include <iostream>

int main(){
    int t,N,K,temp,ans;
    std::cin>>t;
    while(t--){
        std::cin>>K>>N;
        ans = temp = 1;
        for(int i = N; i > N-K; i--){
            ans *= i;
            ans /= temp++;
        }
        std::cout<<ans<<'\n';
    }
    return 0;
}