#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int N , t , cnt=0; cin >> N;
    int arr[1001]= {0};
    arr[1] = 1;

    for(int i = 2; i<=sqrt(1000); i++){
        for(int j = 2 *i; j<= 1000; j+=i ){
            arr[j] = 1;
        }
    }

    for(int i=0; i<N; i++){
        cin >>  t;
        if(!arr[t]) cnt++;
    }

    cout << cnt;

    return 0;
}