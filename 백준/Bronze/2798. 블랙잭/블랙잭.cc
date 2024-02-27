#include <iostream>
int main(){
    int N,M,Ans;
    int* arr;
    std::cin>>N>>M;
    Ans = 0;
    arr = new int[N];
    for(int i=0; i<N; i++){
        std::cin>>arr[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if(i != j && j != k && i != k){
                    int temp = arr[i] + arr[j] + arr[k];
                    if (temp <= M && temp > Ans)
                    {
                        Ans = temp;
                    }
                }
            }
        }
    }

    std::cout<<Ans;
    delete[] arr;
    return 0;
}