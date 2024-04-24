#include <iostream>

int main(){
    int count[10] = {0};
    int a,b,c;
    int ans = 1;
    std::cin>>a>>b>>c;
    ans = a * b * c;

    while(ans){
        count[ans%10]++;
        ans /= 10;
    }

    for(int i=0; i<10; i++){
        std::cout<<count[i]<<'\n';
    }
    return 0;
}