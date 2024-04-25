#include <iostream>

int main(){
    long long sum = 0;
    int N;
    char str[51] = {0};
    std::cin>>N;

    long long temp = 1;
    for(int i=0; i<N; i++){
        std::cin>>str[i];

        sum += ((str[i] - 'a' + 1) * temp) % 1234567891;
        temp = (temp * 31) % 1234567891;
    }
    std::cout << sum % 1234567891;
    return 0;
}