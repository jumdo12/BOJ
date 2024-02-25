#include <iostream>
int main(){
    int arr[1000001]={0};
    int T;
    arr[1] =1;
    std::cin >> T;
    while(T != -1){
        int cnt = 0,sum = 0;
        for(int i=2; i<=T/2; i++){
            if(T % i == 0){
                arr[i] = 1;
                arr[T/i] = 1;
            }
        }

        for(int i=1; i<T;i++){
            if(arr[i]){
                sum += i;
                cnt++;
            }
        }

        if(sum == T){
            std::cout<<T<<" = ";
            int idx = 1;
            for(int i=1; i<=T; i++){
                if(arr[i]){
                    std::cout<<i;
                    if (idx < cnt)
                    {
                        std::cout << " + ";
                        idx++;
                    }
                }
            }
            std::cout<<std::endl;
        }
        else{
            std::cout << T << " is NOT perfect." << std::endl;
        }

        for(int i=2; i<=T; i++){
            arr[i] = 0;
        }
        std::cin>>T;
    }
    return 0;
}