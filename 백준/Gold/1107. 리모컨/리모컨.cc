#include <iostream>
#include <string>

int Nums[10] = {0};

int abs(int n){
    return n > 0 ? n : -n;
}

int min(int a, int b){
    return a > b ? b : a;
}

int check(int N){
    std::string str = std::to_string(N);
    for(int i=0; i<str.length(); i++){
        if(Nums[str[i]-'0'])  return 0;
    }
    return 1;
}

int main(){
    int N,t ,broken,ans;

    std::cin>>N;
    std::cin>>t;

    for(int i=0; i<t; i++){
        std::cin>>broken;
        Nums[broken] = 1;
    }

    ans = abs(N-100);

    for(int i=0; i<= 1000000; i++){
        if(check(i)){
            int tmp = abs(N - i) + std::to_string(i).length();
            ans = min(ans,tmp);
        }
    }

    std::cout<<ans;

    return 0;
}