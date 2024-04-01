#include <iostream>

int abs(int a){
    return a > 0 ? a : -a;
}

int gcd(int a, int b){
    if(b == 0)  return a;
    else    return gcd(b , a % b);
}

int main(){
    int N,S,ans;
    int arr[100001] = {0};

    std::cin>>N>>S;
    for(int i=0; i<N; i++){
        std::cin>>arr[i];
        arr[i] = abs(arr[i] - S);
    }

    ans = arr[0];
    for(int i=1; i < N; i++){
        ans = gcd(ans , arr[i]);
    }
    std::cout<<ans;

    return 0;
}