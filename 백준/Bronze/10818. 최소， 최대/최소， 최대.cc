#include <iostream>
int main(){
    int Max = -1000001 , Min = 10000001 , N ,temp;
    std::cin >> N;
    for(int i=0; i<N; i++){
        std::cin >> temp;
        if(temp > Max) Max = temp;
        if(temp < Min) Min = temp;
    }
    std::cout << Min << " " << Max;

    return 0;
}