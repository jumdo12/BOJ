#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int M,N; cin >> M >> N;
    int arr[1000001]= {0};
    arr[1] = 1;

    for(int i = 2; i<=sqrt(1000000); i++){
        if(!arr[i]){
            for(int j = i *i; j<= 1000000; j+=i ){
                arr[j] = 1;
            }
        }
    }

    for(int i = M; i<= N; i++){
        if(!arr[i]){
            cout << i << '\n';
        }
    }

    return 0;
}