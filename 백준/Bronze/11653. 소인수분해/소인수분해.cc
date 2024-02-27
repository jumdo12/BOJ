#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int N,tmp; cin >> N;
    tmp = N;
    int arr[10000001]= {0};
    arr[1] = 1;

    for(int i = 2; i<=sqrt(10000000); i++){
        if(!arr[i]){
            for(int j = 2 *i; j<= 10000000; j+=i ){
                arr[j] = 1;
            }
        }
    }

    for(int i = 2; i<=N; i++){
        if(!arr[i] && N % i == 0){
            while(!(tmp % i)){
                cout << i << endl;
                tmp /=i;       
            }
        }
    }
    

    return 0;
}