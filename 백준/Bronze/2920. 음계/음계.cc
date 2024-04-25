#include <iostream>

int main(){
    int arr[8];
    std::cin>>arr[0];
    int a , c;
    a = c = 1;
    for(int i=1; i<8; i++){
        std::cin>>arr[i];
        if(arr[i] != arr[i-1] + 1){
            a = 0;
        }
        if(arr[i] != arr[i-1] - 1){
            c = 0;
        }
    }
    if(a){
        std::cout << "ascending";
    }
    else if(c){
        std::cout << "descending";
    }
    else{
        std::cout<<"mixed";
    }
    return 0;
}