#include <iostream>

int gcd(int a, int b){
    if(b == 0)  return a;
    else    return gcd(b,a%b);
}

int main(){
    int N;
    int t;
    long long sum;
    int arr[100] = {0};

    std::cin>>N;
    while(N--){
        std::cin>>t;
        sum = 0;
        for(int i=0; i<t; i++){
            std::cin>>arr[i];
        }
        for(int i=0; i<t-1; i++){
            for(int j=i+1; j<t; j++){
                sum += gcd(arr[i],arr[j]);
            }
        }
        std::cout<<sum<<'\n';
    }
    return 0;
}