#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int N,cnt;
    int arr[1000001]= {0};
    arr[1] = 1;

    for(int i = 2; i<=sqrt(1000000); i++){
        if(!arr[i]){
            for(int j = i *i; j<= 1000000; j+=i ){
                arr[j] = 1;
            }
        }
    }

    cin >> N;

    while(N>0){
        cnt = 0;
        for(int i = N+1; i<=2 * N; i++){
            if(!arr[i]){
                cnt++;
            }
        }
        cout << cnt << endl;
        cin >> N;
    }

    return 0;
}