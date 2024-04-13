#include <iostream>

int main(){
    int N,max;
    int arr[1001],dp1[1001],dp2[1001];
    std::cin>>N;
    for(int i=0; i<N; i++){
        std::cin>>arr[i];
        dp1[i] = 0;
        dp2[i] = 0;
    }

    for(int i=0; i<N; i++){
        int j;
        max = 0;
        for (j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                if (max < dp1[j]){
                    max = (max > dp1[j] ? max : dp1[j]);
                }
            }
        }
        dp1[i] = max + 1;
    }

    for(int i = N-1; i >= 0; i--){
        int j;
        max = 0;
        for(j = N-1; j > i; j--){
            if(arr[i] > arr[j]){
                if(max < dp2[j]){
                    max = (max > dp2[j] ? max : dp2[j]);
                }
            }
        }
        dp2[i] = max + 1;
    }

    max = 0;
    for(int i=0; i<N; i++){
        if(dp1[i] + dp2[i] > max)   max = dp1[i] + dp2[i];
    }

    std::cout<<max-1;

    return 0;
}