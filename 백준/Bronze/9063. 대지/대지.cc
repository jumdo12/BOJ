#include <iostream>

#define Max 10001
#define Min -10001

int main(){
    int X,Y,N;
    int X_Max,X_Min,Y_Max,Y_Min;

    X_Max = Y_Max = Min;
    X_Min = Y_Min = Max;

    std::cin>>N;
    if(N == 0 || N == 1){
        std::cout<<0;
        return 0;
    }

    for(int i=0; i<N; i++){
        std::cin>>X>>Y;
        if(X > X_Max)   X_Max = X;
        if(X < X_Min)   X_Min = X;
        if(Y > Y_Max)   Y_Max = Y;
        if(Y < Y_Min)   Y_Min = Y;    
    }
    std::cout<<(X_Max - X_Min) * (Y_Max - Y_Min);
    return 0;
}