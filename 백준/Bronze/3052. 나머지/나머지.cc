#include <iostream>

int main(){
    int temp,cnt=0;
    int arr[42]={0};
    for(int i=0; i<10; i++){
        std::cin>>temp;
        arr[temp%42]++;
    }
    for(int i=0; i<42;i++){
        if(arr[i]) cnt++;
    }
    std::cout<<cnt;
    return 0;
}