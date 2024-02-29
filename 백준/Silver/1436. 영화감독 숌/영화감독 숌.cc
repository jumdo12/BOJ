#include <iostream>

int main(){
    int N;
    std::cin>>N;
    int arr[10005] ={0},check[8];
    int idx= 1,j=0;
    for(int i=666; i<10000666; i++){
        int temp = i;
        while(temp){
            check[j++] = temp%10;
            temp /= 10;
        }
        for(int k = 0; k <= j-3; k++){
            if((check[k]==6)&&(check[k+1] == 6) && (check[k+2] == 6)){
                arr[idx++] = i;
                break;
            }
        }
        j=0;
        if(idx > 10000)   break;
    }
    std::cout<<arr[N];
    return 0;
}