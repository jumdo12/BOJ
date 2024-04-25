#include <iostream>

int pow(int x, int n){
    int tmp = 1;
    for(int i=0; i<n; i++){
        tmp *= x;
    }
    return tmp;
}

int main(){
    int sum = 0;
    int N;
    char str[5] = {0};
    std::cin>>N;

    for(int i=0; i<N; i++){
        std::cin>>str[i];
        sum += ( str[i] - 'a' + 1 ) * pow(31,i);
    }
    std::cout<<sum;
    return 0;
}