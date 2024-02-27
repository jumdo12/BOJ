#include <iostream>
int main(){
    int X,Y,W,H,dist[4],Min = 10000;
    std::cin >> X>>Y>>W>>H;
    dist[0] = X;
    dist[1] = H - Y;
    dist[2] = W - X;
    dist[3] = Y;
    for(int i=0; i<4; i++){
        if(dist[i] < Min)   Min = dist[i];
    }
    std::cout<<Min;
    return 0;
}