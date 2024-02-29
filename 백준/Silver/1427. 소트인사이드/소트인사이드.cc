#include <iostream>
#define SWAP(x,y,z) ((z=x),(x=y),(y=z))

int main(){
    int N,cnt=0;
    std::cin>>N;
    int arr[10]={0};
    
    int temp = N;
    while(temp){
        arr[cnt++] = temp % 10;
        temp /= 10;
    }

    for (int i = cnt; i > 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            int temp;
            if (arr[j] < arr[j + 1])
                SWAP(arr[j], arr[j + 1], temp);
        }
    }

    for(int i=0; i<cnt;i++){
        std::cout<<arr[i];
    }

    return 0;
}