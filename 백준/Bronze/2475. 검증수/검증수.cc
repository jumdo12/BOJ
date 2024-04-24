#include <iostream>

int main(){
    int arr[5];
    int sum = 0;
    for(int i=0; i<5; i++){
        std::cin>>arr[i];
        sum += (arr[i] * arr[i]);
    }
    std::cout<<sum%10;
    return 0;
}