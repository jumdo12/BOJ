#include <iostream>

typedef struct{
    int w;
    int h;
}data;

int check(data* arr, int n,int m){
    int idx = 1;
    for(int i = 0; i<m; i++){
        if(arr[i].w > arr[n].w && arr[i].h > arr[n].h){
            idx++;
        }
    }
    return idx;
}

int main(){
    int N,w,h;
    data arr[50];
    std::cin>>N;
    for(int i=0; i<N; i++){
        std::cin>>w>>h;
        arr[i].w = w;
        arr[i].h = h;
    }

    for(int i=0; i<N; i++){
        std::cout<< check(arr,i,N)<<" ";
    }

    return 0;
}