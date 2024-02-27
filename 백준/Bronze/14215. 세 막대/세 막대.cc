#include <iostream>

int main(){
    int dist[3]={0};
    for(int i=0; i<3; i++){
        std::cin>>dist[i];
    }
    for(int i=2; i>0; i--){
        for(int j=0; j<i; j++){
            if(dist[j] > dist[j+1]){
                int temp = dist[j];
                dist[j] = dist[j+1];
                dist[j+1] = temp;
            }
        }
    }

    if(dist[0] + dist[1] > dist[2]){
        std::cout<<dist[0]+dist[1]+dist[2];
    }
    else{
        std::cout<<2*(dist[0]+dist[1])-1;
    }
    return 0;
}